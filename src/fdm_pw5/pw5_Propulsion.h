/****************************************************************************//*
 * Copyright (C) 2021 Marek M. Cel
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ******************************************************************************/
#ifndef PW5_PROPULSION_H
#define PW5_PROPULSION_H

////////////////////////////////////////////////////////////////////////////////

#include <fdm/main/fdm_Propulsion.h>

#include <fdm/models/fdm_WinchLauncher.h>

////////////////////////////////////////////////////////////////////////////////

namespace fdm
{

class PW5_Aircraft;    // aircraft class forward declaration

/**
 * @brief PW-5 propulsion class.
 */
class PW5_Propulsion : public Propulsion
{
public:

    /** Constructor. */
    PW5_Propulsion( const PW5_Aircraft *aircraft, Input *input );

    /** Destructor. */
    ~PW5_Propulsion();

    /**
     * Reads data.
     * @param dataNode XML node
     */
    void readData( XmlNode &dataNode );

    /** Computes force and moment. */
    void computeForceAndMoment();

    /** Updates propulsion. */
    void update();

private:

    const PW5_Aircraft *_aircraft;  ///< aircraft model main object

    WinchLauncher *_winchLauncher;  ///< winch launcher
};

} // end of fdm namespace

////////////////////////////////////////////////////////////////////////////////

#endif // PW5_PROPULSION_H
