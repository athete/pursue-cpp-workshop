void MakeHist_JetPt(const char* filename, bool png = true) {
    // Create an RDataFrame
    ROOT::RDataFrame df("Events", filename);

    // Define a histogram for the Jet_pt branch
    auto hist = df.Histo1D({"jetPtHist", "Jet pt", 100, 10, 1000}, "Jet_pt");  // Adjust bins and range as needed

    hist->SetTitle("Jet p_{T} Distribution; Jet p_{T} (GeV); Events");

    // Create canvas
    auto canvas = new TCanvas("canvas", "Jet pt Histogram", 800, 600);
    
    // Draw the histogram
    hist->Draw();

    if (png){
        canvas->SaveAs("JetPtHistogram.png");
        delete canvas;
    } else {
        canvas->Update();
    }
}