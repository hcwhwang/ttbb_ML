#from keras.datasets import mnist
from sklearn import datasets
from sklearn.model_selection import train_test_split
import numpy as np
from keras.models import Sequential
from keras.layers import Dense, Activation
from keras.optimizers import SGD,Adam
from keras import backend as K
from ROOT import *

gStyle.SetOptStat(0)
#def weight_variable(shape):
#  return K.truncated_normal(shape, stddev=0.01)

def DNN(nLayer=1, nNeuron=50, nEpoch=100):
  outName = "_%i_%i_%i" % (nLayer, nNeuron, nEpoch)
  n_hidden = nNeuron
  epochs = nEpoch
  fX = open("inputX.txt", 'r')
  fY = open("inputY.txt", 'r')
  n = 0
  while True:
    line = fX.readline()
    if not line: break
    n += 1
  N = 30000
  indices = np.random.permutation(range(n))[:N]
  X_train_raw, Y_train_raw = [], []

  fX = open("inputX.txt", 'r')
  fY = open("inputY.txt", 'r')
  while True:
    lineX = fX.readline()
    lineY = fY.readline()
    if not lineX: break
    tempX, tempY = [], []
    xArray = lineX.split(" ")
    yArray = lineY.split(" ")
    #for i in xArray: tempX.append(float(i))
    tempX.append(float(xArray[0]))  #jetPt3 
    tempX.append(float(xArray[1]))  #jetPt4
    tempX.append(float(xArray[2]))  #jetEta3
    tempX.append(float(xArray[3]))  #jetEta4
    tempX.append(float(xArray[4]))  #jetPhi3
    tempX.append(float(xArray[5]))  #jetPhi4
    tempX.append(float(xArray[6]))  #jetM3
    tempX.append(float(xArray[7]))  #jetM4
    tempX.append(float(xArray[8]))  #csv3
    tempX.append(float(xArray[9]))  #csv4
    tempX.append(float(xArray[10])) #bbM
    tempX.append(float(xArray[11])) #bbDR
    tempX.append(float(xArray[12])) #nbjetM
    for i in yArray: tempY.append(float(i))
    #if int(yArray[0])+int(yArray[1])==1: 
    #  tempY.append(1)
    #else: 
    #  tempY.append(0)
    X_train_raw.append(tempX)
    Y_train_raw.append(tempY)

  X_train, Y_train = [], []
  for i, order in enumerate(indices):
    X_train.append(X_train_raw[order])
    Y_train.append(Y_train_raw[order])

  X_test, Y_test = [], []
  for i, sub in enumerate(X_train_raw):
    if i in indices: continue
    X_test.append(sub)
    Y_test.append(Y_train_raw[i])

  n_in = len(X_train_raw[0])
  n_out = len(Y_train_raw[0])

  model = Sequential()
  model.add(Dense(n_hidden, input_dim=n_in ))
  model.add(Activation('tanh'))

  for i in range(nLayer):
    model.add(Dense(n_hidden))
    model.add(Activation('tanh'))

  model.add(Dense(n_out))
  model.add(Activation('tanh'))

  #model.add(Dense(n_out))
  #model.add(Activation('softmax'))

  #model.add(Dense(n_out))
  #model.add(Activation('softmax'))

  #model.compile(loss='categorical_crossentropy',
  model.compile(loss='binary_crossentropy',
                #optimizer=SGD(lr=0.01, momentum=0.9, nesterov=True),
                #optimizer=SGD(lr=0.01),
                optimizer=Adam(lr=0.001, beta_1=0.9, beta_2=0.999),
                metrics=['accuracy'])

  batch_size = 100

  X_train = np.array(X_train)
  Y_train = np.array(Y_train)
  X_test = np.array(X_test)
  Y_test = np.array(Y_test)
  hist = model.fit(X_train, Y_train, epochs=epochs, batch_size=batch_size, validation_data=(X_test, Y_test))

  f1 = TGraph()
  f1.SetMinimum(0.)
  f1.SetMaximum(1.)
  f1.SetLineColor(kRed)
  f2 = TGraph()
  f2.SetLineColor(kBlue)
  for i,value in enumerate(hist.history['val_loss']):
    f1.SetPoint(i,i+1,value)
  for i,value in enumerate(hist.history['val_acc']):
    f2.SetPoint(i,i+1,value)
  #c = TCanvas("c","c",500,500)

  #f1.Draw("AL")
  #f2.Draw("same")
  predictions = model.predict(X_test)
  hDNN = TH1F("DNN_output","DNN_output", 50,0,1)
  hSig = TH1F("hSig"+outName,"hSig", 50,0,1)
  hSig.SetLineColor(kRed)
  hBkg = TH1F("hBkg"+outName,"hBkg", 50,0,1)
  hBkg.SetLineColor(kBlue)
  for i,val in enumerate(predictions):
    if Y_test[i]==1: hSig.Fill(predictions[i])
    else: hBkg.Fill(predictions[i])

  hList = [hSig, hBkg]
  hDNN.SetMinimum(0)
  hDNN.SetMaximum(max(h.GetMaximum()/h.Integral() for h in hList)*1.3)
  leg = TLegend(0.65, 0.7, 0.92, 0.92)
  leg.SetFillStyle(0)
  leg.SetBorderSize(0)
  leg.AddEntry(hSig, "ttbb+ttbj", "l")
  leg.AddEntry(hBkg, "ttcc+ttLF", "l")

  c = TCanvas("c"+outName, "c"+outName, 500,500)
  hDNN.Draw()
  for h in hList: 
    h.DrawNormalized("sameHIST")
    h.Write()
    h.Scale(1./h.Integral())
  leg.Draw()
  print hSig.Integral(50,-1)
  c.SaveAs("DNN_output%s.pdf" % outName)


  gAUC = TGraph()
  tempSigEff = 0.
  tempBkgRej = 1.
  AUC = 0.
  for i in range(51):
    sigEff = hSig.Integral(50-i+1,-1)
    bkgRej = 1 - hBkg.Integral(50-i+1,-1)
    gAUC.SetPoint(i,sigEff,bkgRej)
    AUC += (tempBkgRej+bkgRej)/2.*abs(sigEff-tempSigEff)
    tempSigEff = sigEff
    tempBkgRej = bkgRej
  #gAUC.SetPoint(50,sigEff,bkgRej)
  c1 = TCanvas("c1"+outName,"c1"+outName,500,500)
  gAUC.Draw("AL")
  gAUC.SetTitle("%f" % AUC)
  gAUC.SetName(outName)
  gAUC.Write()
  print AUC

  c1.SaveAs("ROC%s.pdf" % outName)

outFile = TFile.Open("output.root","recreate")
nLayerArray = [1,2,3,4,5,6,7,8,9,10]
nNeuronArray = [10,20,50,100,150]
nEpochArray = [100,150,200,250]
for i in nLayerArray:
  for j in nNeuronArray:
    if i!=2 and j!=50: continue
    DNN(i,j,150)
outFile.Close
