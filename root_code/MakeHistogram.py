import ROOT

def MakeHist_JetPt(filename, png=True):
    df = ROOT.RDataFrame("Events", filename)
    
    hist = df.Histo1D(("jetPtHist", "Jet p_{T} Distribution; Jet p_{T} (GeV); Events", 100, 10, 1000), "Jet_pt")

    canvas = ROOT.TCanvas("canvas", "Jet pt Histogram", 800, 600)

    hist.Draw()

    if png:
        canvas.SaveAs("JetPtHistogram.png")
    else:
        canvas.Update()
        input("Press Enter to continue...") 

MakeHist_JetPt("scripts/data.root", png=True)