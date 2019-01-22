from ROOT import *

gStyle.SetOptStat(0)
gROOT.SetBatch(True)
def mAND(aaa,bbb):
  return "(" +aaa+ " && "+bbb+")"
def op_(aaa):
  return "!(" + aaa + ")"


store = "/xrootd/store/user/chanwook/ttbb/final/final/"
#overallCut = "tri>0 && filtered==1 && step>=5 && (channel==1 || channel==2 || channel==3) && nbjetL30>=3"
overallCut = "tri>0 && filtered==1 && step>=5 && (channel==1 || channel==2 || channel==3)"
#overallCut = "filtered==1 && step>=5"

#visible="(NJets20>=6 && NbJets20>=2 && (((lepton1_pt>20 && abs(lepton1_eta)<2.4)) || (lepton2_pt>20 && abs(lepton2_eta)<2.4)))"
visible="(NJets30>=4 && NbJets30>=2 && lepton1_pt>20 && lepton2_pt>20 && abs(lepton1_eta)<2.4 && abs(lepton2_eta)<2.4)"

ttbb = mAND("(NbJets30>=3)",visible)
ttccLF = mAND("(NbJets30<=2)",visible)

f = TFile.Open(store + "TT_powheg_tot.root")
t = f.Get("cattree/nom")
cutSig = mAND(ttbb,overallCut)
cutBkg = mAND(ttccLF,overallCut)
name = ["csv3","csv4","jetPt3","jetPt4","jetEta3","jetEta4","jetPhi3","jetPhi4","jetM3","jetM4","bbM","bbDR","nbjetM","nbjetT"]
binInfo = [[50,0,1],[50,0,1],[50,0,300],[50,0,300],[50,-2.5,2.5],[50,-2.5,2.5],[50,-3.5,3.5],[50,-3.5,3.5],[50,0,300],[50,0,300],[50,0,500],[50,0,5],[10,0,10],[10,0,10]]
var = ["jets_bDiscriminatorCSV[csvd_jetid[2]]","jets_bDiscriminatorCSV[csvd_jetid[3]]","jets_pt[csvd_jetid[2]]","jets_pt[csvd_jetid[3]]","jets_eta[csvd_jetid[2]]","jets_eta[csvd_jetid[3]]","jets_phi[csvd_jetid[2]]","jets_phi[csvd_jetid[3]]","jets_m[csvd_jetid[2]]","jets_m[csvd_jetid[3]]","bbM","bbDR","nbjetM30","nbjetT30"]
doLog = [False,False, True, True, True, True, True, True, True, True, True, True, False, False]
for i, n in enumerate(name):
  print n
  hSigName = "hSig"+n
  hBkgName = "hBkg"+n
  binning = binInfo[i]
  hSig = TH1F(hSigName,n,binning[0],binning[1],binning[2])
  hSig.SetLineColor(kRed)
  hBkg = TH1F(hBkgName,n,binning[0],binning[1],binning[2])
  hBkg.SetLineColor(kBlue)

  t.Project(hSigName,var[i],cutSig)
  t.Project(hBkgName,var[i],cutBkg)

  hList = [hSig, hBkg]
  hMax = max(h.GetMaximum()/h.Integral() for h in hList)
  hFrame = TH1F(n,n,binning[0],binning[1],binning[2])
  hFrame.SetMinimum(0.0001)
  if doLog[i] == True: hFrame.SetMaximum(hMax*5)
  else: hFrame.SetMaximum(hMax*1.5)

  leg = TLegend(0.65, 0.7, 0.92, 0.92)
  leg.SetFillStyle(0)
  leg.SetBorderSize(0)
  leg.AddEntry(hSig, "ttbb+ttbj", "l")
  leg.AddEntry(hBkg, "ttcc+ttLF", "l")

  c = TCanvas(n,n,500,500)
  if doLog[i] == True: c.SetLogy()
  hFrame.Draw()
  for h in hList: h.DrawNormalized("sameHIST")
  leg.Draw()
  c.SaveAs("%s.pdf" % n)
