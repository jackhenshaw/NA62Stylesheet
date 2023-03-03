#ifndef  __NA62STYLE_H
#define __NA62STYLE_H

#include "TStyle.h"

void SetNA62Style();

TStyle* NA62Style();

TPaveText* NA62Label(double x1, double y1, double x2, double y2, const char* note="");
TPaveText* NA62Label(std::string pos="", const char* note="");

Int_t GetNA62Color(int icol);
Int_t GetNA62Color(std::string col);

#endif // __NA62STYLE_H
