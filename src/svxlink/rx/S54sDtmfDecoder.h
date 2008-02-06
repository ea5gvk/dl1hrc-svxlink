/**
@file	 S54sDtmfDecoder.h
@brief   This file contains a class that add support for the S54S interface
@author  Tobias Blomberg / SM0SVX
@date	 2008-02-04

\verbatim
SvxLink - A Multi Purpose Voice Services System for Ham Radio Use
Copyright (C) 2004-2007  Tobias Blomberg / SM0SVX

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


#ifndef S54S_DTMF_DECODER_INCLUDED
#define S54S_DTMF_DECODER_INCLUDED


/****************************************************************************
 *
 * System Includes
 *
 ****************************************************************************/

#include <sigc++/sigc++.h>


/****************************************************************************
 *
 * Project Includes
 *
 ****************************************************************************/

#include <AudioSink.h>


/****************************************************************************
 *
 * Local Includes
 *
 ****************************************************************************/



/****************************************************************************
 *
 * Forward declarations
 *
 ****************************************************************************/

namespace Async
{
  class Serial;
};


/****************************************************************************
 *
 * Namespace
 *
 ****************************************************************************/

//namespace MyNameSpace
//{

/****************************************************************************
 *
 * Defines & typedefs
 *
 ****************************************************************************/

/*
 *----------------------------------------------------------------------------
 * Macro:   
 * Purpose: 
 * Input:   
 * Output:  
 * Author:  
 * Created: 
 * Remarks: 
 * Bugs:    
 *----------------------------------------------------------------------------
 */


/*
 *----------------------------------------------------------------------------
 * Type:    
 * Purpose: 
 * Members: 
 * Input:   
 * Output:  
 * Author:  
 * Created: 
 * Remarks: 
 *----------------------------------------------------------------------------
 */
    


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

/*
 *----------------------------------------------------------------------------
 * Class:     S54sDtmfDecoder
 * Purpose:   
 * Inherits:  
 * Input:     
 * Output:    
 * Author:    Tobias Blomberg, SM0SVX
 * Created:   2008-02-04
 * Remarks:   
 * Bugs:      
 *----------------------------------------------------------------------------
 */   
class S54sDtmfDecoder : public SigC::Object, public Async::AudioSink
{
  public:
    /**
     * @brief 	Default constructor
     */
    S54sDtmfDecoder(void);
    
    /**
     * @brief 	Destructor
     */
    ~S54sDtmfDecoder(void);
    
    /**
     * @brief 	Set the time the detector should hang on a digit
     * @param 	hangtime_ms The hangtime in milliseconds
     *
     * Use this function to set the time that a digit should be considered as
     * active after the detector has said it's idle. Higher values make the
     * detector perform better when subjected to mobile flutter.
     */
    void setHangtime(int hangtime_ms) { hangtime = 8000 * hangtime_ms / 1000; }
    
    /**
     * @brief 	Write samples into the DTMF decoder
     * @param 	samples The buffer containing the samples
     * @param 	count The number of samples in the buffer
     * @return	Returns the number of samples that has been taken care of
     */
    int writeSamples(const float *samples, int count) { return count; }
    
    /**
     * @brief 	Tell the DTMF decoder to flush the previously written samples
     *
     * This function is used to tell the sink to flush previously written
     * samples. When done flushing, the sink should call the
     * sourceAllSamplesFlushed function.
     */
    void flushSamples(void)
    {
      sourceAllSamplesFlushed();
    }
    
    /**
     * @brief 	Return the active digit
     * @return	Return the active digit if any or a '?' if none.
     */
    char activeDigit(void) const
    {
      return (state != STATE_IDLE) ? last_detected_digit : '?';
    }

    /*
     * @brief 	A signal that is emitted when a DTMF digit is first detected
     * @param 	digit The detected digit
     */
    SigC::Signal1<void, char> digitActivated;

    /*
     * @brief 	A signal that is emitted when a DTMF digit is no longer present
     * @param 	digit 	  The detected digit
     * @param 	duration  The time that the digit was active
     */
    SigC::Signal2<void, char, int> digitDeactivated;
    
    
  protected:
    
  private:
    typedef enum
    {
      STATE_IDLE, STATE_ACTIVE, STATE_HANG
    } State;
    
    char      	    last_detected_digit;
    State     	    state;
    int       	    hangtime;
    Async::Serial   *serial;
    
    void charactersReceived(char *buf, int len);

};  /* class DtmfDecoder */


//} /* namespace */

#endif /* S54S_DTMF_DECODER_INCLUDED */



/*
 * This file has not been truncated
 */
