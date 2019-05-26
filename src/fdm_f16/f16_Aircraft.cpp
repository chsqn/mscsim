/****************************************************************************//*
 * Copyright (C) 2019 Marek M. Cel
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

#include <fdm_f16/f16_Aircraft.h>

////////////////////////////////////////////////////////////////////////////////

using namespace fdm;

////////////////////////////////////////////////////////////////////////////////

F16_Aircraft::F16_Aircraft() :
    Aircraft(),

    m_aero ( 0 ),
    m_ctrl ( 0 ),
    m_gear ( 0 ),
    m_mass ( 0 ),
    m_prop ( 0 )
{
    Aircraft::m_aero = m_aero = new F16_Aerodynamics( this );
    Aircraft::m_ctrl = m_ctrl = new F16_Controls( this );
    Aircraft::m_gear = m_gear = new F16_LandingGear( this );
    Aircraft::m_mass = m_mass = new F16_Mass( this );
    Aircraft::m_prop = m_prop = new F16_Propulsion( this );
}

////////////////////////////////////////////////////////////////////////////////

F16_Aircraft::~F16_Aircraft()
{
    if ( m_aero ) delete m_aero;
    m_aero = 0;

    if ( m_ctrl ) delete m_ctrl;
    m_ctrl = 0;

    if ( m_gear ) delete m_gear;
    m_gear = 0;

    if ( m_mass ) delete m_mass;
    m_mass = 0;

    if ( m_prop ) delete m_prop;
    m_prop = 0;
}

////////////////////////////////////////////////////////////////////////////////

void F16_Aircraft::init( bool engineOn )
{
    readData( "data/fdm/f16/f16_fdm.xml" );

    ///////////////////////////
    Aircraft::init( engineOn );
    ///////////////////////////
}