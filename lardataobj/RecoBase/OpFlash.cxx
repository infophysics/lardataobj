////////////////////////////////////////////////////////////////////////
//
// \brief Definition of OpFlash reconstruction object
//
// \author bjpjones@mit.edu
//         cschiu@mit.edu
//
////////////////////////////////////////////////////////////////////////

#include "lardataobj/RecoBase/OpFlash.h"

#include <numeric> // std::accumulate()
#include <utility> // std::move()

namespace recob{

  //----------------------------------------------------------------------
  OpFlash::OpFlash(double time, double timewidth, double abstime, unsigned int frame,
		   std::vector<double> PEperOpDet,
		   bool InBeamFrame, int onBeamTime, double FastToTotal,
		   double yCenter, double yWidth,
		   double zCenter, double zWidth,
		   std::vector<double> WireCenters,
		   std::vector<double> WireWidths)
    : fTime        { time }
    , fTimeWidth   { timewidth }
    , fAbsTime     { abstime }
    , fFrame       { frame }
    , fPEperOpDet  { std::move(PEperOpDet) }
    , fWireCenters { std::move(WireCenters) }
    , fWireWidths  { std::move(WireWidths) }
    , fYCenter     { yCenter }
    , fYWidth      { yWidth }
    , fZCenter     { zCenter }
    , fZWidth      { zWidth }
    , fFastToTotal { FastToTotal }
    , fInBeamFrame { InBeamFrame }
    , fOnBeamTime  { onBeamTime }
  {
  }

  //----------------------------------------------------------------------
  bool operator < (const OpFlash & a, const OpFlash & b)
  {
    return a.Time() < b.Time();
  }

  //----------------------------------------------------------------------
  double OpFlash::TotalPE() const
  {
    return std::accumulate(fPEperOpDet.begin(), fPEperOpDet.end(), 0.0);
  }



}
