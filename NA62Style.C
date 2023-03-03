//
// NA62 Style, based on a style file from ATLAS
//

#include <iostream>

#include "NA62Style.h"

#include "TROOT.h"

void SetNA62Style ()
{
  static TStyle* na62Style = 0;
  std::cout << "\nApplying NA62 style settings...\n" << std::endl ;
  if ( na62Style==0 ) na62Style = NA62Style();
  gROOT->SetStyle("NA62");
  gROOT->ForceStyle();
}

TStyle* NA62Style()
{
  TStyle *na62Style = new TStyle("NA62","NA62 style");

  // use plain black on white colors
  Int_t icol=0; // WHITE
  na62Style->SetFrameBorderMode(icol);
  na62Style->SetFrameFillColor(icol);
  na62Style->SetCanvasBorderMode(icol);
  na62Style->SetCanvasColor(icol);
  na62Style->SetPadBorderMode(icol);
  na62Style->SetPadColor(icol);
  na62Style->SetStatColor(icol);

  // set the paper & margin sizes
  na62Style->SetPaperSize(20,26);

  // set margin sizes
  na62Style->SetPadRightMargin(0.03);
  na62Style->SetPadTopMargin(0.06);
  na62Style->SetPadBottomMargin(0.14);
  na62Style->SetPadLeftMargin(0.09);

  // set title offsets (for axis label)
  na62Style->SetTitleXOffset(1.2);
  na62Style->SetTitleYOffset(0.8);

  // Change to Helvetica
  // - if font=42, tsize is fraction of pad. (0.05)
  // - if font=43, tsize is pixels (32)
  Int_t font=42;
  Double_t tsize=0.05;
  na62Style->SetTextFont(font);
  na62Style->SetTextSize(tsize);
  na62Style->SetLabelFont(font,"x");
  na62Style->SetTitleFont(font,"x");
  na62Style->SetLabelFont(font,"y");
  na62Style->SetTitleFont(font,"y");
  na62Style->SetLabelFont(font,"z");
  na62Style->SetTitleFont(font,"z");
  na62Style->SetLegendFont(font);
  na62Style->SetLabelSize(tsize,"x");
  na62Style->SetTitleSize(tsize,"x");
  na62Style->SetLabelSize(tsize,"y");
  na62Style->SetTitleSize(tsize,"y");
  na62Style->SetLabelSize(tsize,"z");
  na62Style->SetTitleSize(tsize,"z");
  na62Style->SetLegendTextSize(tsize);

  // use bold lines and markers
  na62Style->SetMarkerStyle(20); // full circle
  na62Style->SetMarkerSize(1.2); // 1.2
  na62Style->SetHistLineWidth(3); // 2
  na62Style->SetLineStyleString(2,"[12 12]"); // postscript dashes

  // get rid of X error bars (TODO: not sure whether to keep this)
  //na62Style->SetErrorX(0.0001);
  // get rid of error bar caps (not sure this is doing anything)
  na62Style->SetEndErrorSize(4.0);

  // do not display any of the standard histogram decorations
  na62Style->SetOptTitle(0);
  na62Style->SetOptStat(0);
  na62Style->SetOptFit(0);

  // put tick marks on top and RHS of plots
  na62Style->SetPadTickX(1);
  na62Style->SetPadTickY(1);
  na62Style->SetTickLength(0.02, "xy");
  na62Style->SetLineWidth(3);

  // Grid
  na62Style->SetGridColor(14); // light-grey
  na62Style->SetGridStyle(3);  // solid line
  na62Style->SetGridWidth(1);

  // 2D colour palette
  na62Style->SetHistLineColor(GetNA62Color(0));
  na62Style->SetPalette(kRainBow); // closest match to matplotlib jet
  na62Style->SetNumberContours(256); // smooth colour bar

  // Legend
  na62Style->SetLegendBorderSize(1);

  return na62Style;
}

TPaveText* NA62Label(double x, double y, const char *note=""){
  TPaveText *na62label = new TPaveText(x, y, x+0.1, y+0.1, "NDC");

  na62label->SetTextFont(42);
  na62label->SetTextSize(0.07);
  na62label->SetFillStyle(0); // transparent
  na62label->SetLineStyle(0); // transparent
  na62label->SetBorderSize(0);

  na62label->AddText("#bf{NA62}");
  if (note) {
    TText *n = na62label->AddText(note);
    n->SetTextSize(0.05);
  }

  return na62label;
}

TPaveText* NA62Label(std::string pos="", const char* note="") {
  TPaveText *na62label = nullptr;

  transform(pos.begin(), pos.end(), pos.begin(), ::toupper);

  if (pos == "TR") na62label = NA62Label(0.82, 0.80, note);
  if (pos == "TL") na62label = NA62Label(0.12, 0.80, note);
  if (pos == "BR") na62label = NA62Label(0.82, 0.17, note);
  if (pos == "BL") na62label = NA62Label(0.12, 0.17, note);

  return na62label;
}

Int_t GetNA62Color(int icol) {
  Int_t blue_index = TColor::GetFreeColorIndex();
  TColor *blue = new TColor(blue_index, 0.101, 0.101, 0.949);

  Int_t orange_index = TColor::GetFreeColorIndex();
  TColor *orange = new TColor(orange_index, 0.977, 0.555, 0.008);

  Int_t green_index = TColor::GetFreeColorIndex();
  TColor *green = new TColor(green_index, 0.000, 0.738, 0.000);

  Int_t red_index = TColor::GetFreeColorIndex();
  TColor *red = new TColor(red_index, 0.996, 0.078, 0.078);

  Int_t purple_index = TColor::GetFreeColorIndex();
  TColor *purple = new TColor(purple_index, 0.445, 0.156, 0.707);

  Int_t brown_index = TColor::GetFreeColorIndex();
  TColor *brown = new TColor(brown_index, 0.430, 0.148, 0.055);

  Int_t pink_index = TColor::GetFreeColorIndex();
  TColor *pink = new TColor(pink_index, 0.938, 0.148, 0.695);

  Int_t grey_index = TColor::GetFreeColorIndex();
  TColor *grey = new TColor(grey_index, 0.496, 0.496, 0.496);

  Int_t yellowgreen_index = TColor::GetFreeColorIndex();
  TColor *yellowgreen = new TColor(yellowgreen_index, 0.672, 0.672, 0.000);

  Int_t cyan_index = TColor::GetFreeColorIndex();
  TColor *cyan = new TColor(cyan_index, 0.008, 0.715, 0.785);

  if (icol == 0) return blue_index;
  if (icol == 1) return orange_index;
  if (icol == 2) return green_index;
  if (icol == 3) return red_index;
  if (icol == 4) return purple_index;
  if (icol == 5) return brown_index;
  if (icol == 6) return pink_index;
  if (icol == 7) return grey_index;
  if (icol == 8) return yellowgreen_index;
  if (icol == 9) return cyan_index;

  return 0;
}

Int_t GetNA62Color(std::string col) {
  if (col=="blue")        return GetNA62Color(0);
  if (col=="orange")      return GetNA62Color(1);
  if (col=="green")       return GetNA62Color(2);
  if (col=="red")         return GetNA62Color(3);
  if (col=="purple")      return GetNA62Color(4);
  if (col=="brown")       return GetNA62Color(5);
  if (col=="pink")        return GetNA62Color(6);
  if (col=="grey")        return GetNA62Color(7);
  if (col=="yellowgreen") return GetNA62Color(8);
  if (col=="cyan")        return GetNA62Color(8);

  std::cout << "unknown colour! defaulting to NA62 blue" << std::endl;
  return GetNA62Color(0);
}
