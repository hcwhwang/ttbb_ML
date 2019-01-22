from ROOT import *


fDNN = TFile.Open("output.root")
for i in fDNN.GetListOfKeys():
  if i.GetClassName()!='TGraph':continue
  if i.GetName() == '_2_150_150': gDNN = fDNN.Get(i.GetName())

gDNN.SetLineWidth(2)
gDNN.SetTitle(";Signal Efficiency;Background Rejection")
fMVA = TFile.Open("TMVA.root")
hBDT = fMVA.Get("Method_BDT/BDT/MVA_BDT_rejBvsS")
hLD = fMVA.Get("Method_LD/LD/MVA_LD_rejBvsS")


gBDT = TGraph()
gBDT.SetLineColor(kRed)
gBDT.SetLineWidth(2)
for i in range(hBDT.GetNbinsX()):
  gBDT.SetPoint(i,0.005+0.01*i,hBDT.GetBinContent(i+1))

gLD = TGraph()
gLD.SetLineColor(kBlue)
gLD.SetLineWidth(2)
for i in range(hLD.GetNbinsX()):
  gLD.SetPoint(i,0.005+0.01*i,hLD.GetBinContent(i+1))

leg = TLegend(0.65, 0.7, 0.92, 0.92)
leg.SetFillStyle(0)
leg.SetBorderSize(0)
leg.AddEntry(gDNN, "DNN", "l")
leg.AddEntry(gBDT, "BDT", "l")
leg.AddEntry(gLD, "LD", "l")
c = TCanvas("c","c",500,500)
gDNN.Draw("AL")
gBDT.Draw("same")
gLD.Draw("same")
leg.Draw()

c.SaveAs("allROC.pdf")

gStyle.SetOptStat(0)
MVA = ["BDT", "LD"]
for i,mva in enumerate(MVA):
  hSig = fMVA.Get("Method_%s/%s/MVA_%s_S" % (mva,mva,mva))
  hBkg = fMVA.Get("Method_%s/%s/MVA_%s_B" % (mva,mva,mva))
  hSig.SetLineColor(kRed)
  hBkg.SetLineColor(kBlue)
  hList = [hSig, hBkg]
  hFrame = TH1F(mva,mva,hSig.GetNbinsX(),hSig.GetXaxis().GetXmin(),hSig.GetXaxis().GetXmax())
  hMax = max(h.GetMaximum()/h.Integral() for h in hList)
  hFrame.SetMinimum(0)
  hFrame.SetMaximum(hMax*1.3)
  c = TCanvas(mva,mva,500,500)
  hFrame.Draw()
  for h in hList: 
    h.SetName("")
    h.DrawNormalized("sameHIST")
  c.SaveAs("%s.pdf"%mva)
