/**
@file	 SquelchInternal.h
@brief   A squelch detector that read squelch state on a pseudo Tty
@author  Tobias Blomberg / SM0SVX & Adi Bier / DL1HRC
@date	 2020-06-09

\verbatim
SvxLink - A Multi Purpose Voice Services System for Ham Radio Use
Copyright (C) 2004-2020  Tobias Blomberg / SM0SVX

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
\endverbatim
*/

#ifndef SQUELCH_INTERNAL_INCLUDED
#define SQUELCH_INTERNAL_INCLUDED


/****************************************************************************
 *
 * System Includes
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Project Includes
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Local Includes
 *
 ****************************************************************************/

//#include "RefCountingInternal.h"
#include "Squelch.h"


/****************************************************************************
 *
 * Forward declarations
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Namespace
 *
 ****************************************************************************/

using namespace sigc;


/****************************************************************************
 *
 * Forward declarations of classes inside of the declared namespace
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Defines & typedefs
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Exported Global Variables
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Class definitions
 *
 ****************************************************************************/

/**
@brief	Squelch detector for a SvxLink internal command
@author Adi Bier / DL1HRC
@date   2020-06-09

This squelch detector read the state of the squelch through a INTERNAL device.  This
can be used to interface SvxLink to any custom hardware using an interface
script.
*/
class SquelchInternal : public Squelch
{
  public:
    /**
     * @brief 	Default constuctor
     */
    SquelchInternal(void) {}

    /**
     * @brief 	Destructor
     */
    ~SquelchInternal(void) {}

    /**
     * @brief 	Initialize the squelch detector
     * @param 	cfg A previsously initialized config object
     * @param 	rx_name The name of the RX (config section name)
     * @return	Returns \em true on success or else \em false
     */
    bool initialize(Async::Config& cfg, const std::string& rx_name)
    {
      if (!Squelch::initialize(cfg, rx_name))
      {
      	return false;
      }
      return true;
    }

    void setSql(bool is_open)
    {
      setSignalDetected(is_open);
    } /* setSql */


  protected:
    /**
     * @brief 	Process the incoming samples in the squelch detector
     * @param 	samples A buffer containing samples
     * @param 	count The number of samples in the buffer
     * @return	Return the number of processed samples
     */
    int processSamples(const float *samples, int count)
    {
      return count;
    }

  private:

    SquelchInternal(const SquelchInternal&);
    SquelchInternal& operator=(const SquelchInternal&);

};  /* class SquelchInternal */


//} /* namespace */

#endif /* SQUELCH_INTERNAL_INCLUDED */



/*
 * This file has not been truncated
 */
