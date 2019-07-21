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
#ifndef FDM_ATMOSPHERE_H
#define FDM_ATMOSPHERE_H

////////////////////////////////////////////////////////////////////////////////

#include <fdm/fdm_Defines.h>

////////////////////////////////////////////////////////////////////////////////

namespace fdm
{

/**
 * @brief US Standard Atmosphere class.
 *
 * <p>This class is used to compute altitude depend atmospheric data. It is
 * based on U.S. Standard Atmosphere 1976 extended by user defined sea level
 * conditions. User defined sea level conditions affect only the lowest layer
 * up to 11,000 m above mean sea level.</p>
 * <p>Model is valid up to 84,852 meters above mean sea level.</p>
 *
 * @see US Standard Atmosphere 1976, NASA, TM-X-74335
 */
class FDMEXPORT Atmosphere
{
public:

    /** Gas species indeces. */
    enum GasSpeciesIndeces
    {
        N2 = 0,                         ///< index of Nitrogen in tables m_m_i and m_f_i
        O2,                             ///< index of Oxygen in tables m_m_i and m_f_i
        Ar,                             ///< index of Argon in tables m_m_i and m_f_i
        CO2,                            ///< index of Carbon Dioxide in tables m_m_i and m_f_i
        Ne,                             ///< index of Neon in tables m_m_i and m_f_i
        He,                             ///< index of Helium in tables m_m_i and m_f_i
        Kr,                             ///< index of Krypton in tables m_m_i and m_f_i
        Xe,                             ///< index of Xenon in tables m_m_i and m_f_i
        CH4,                            ///< index of Methane in tables m_m_i and m_f_i
        H2                              ///< index of Hydrogen in tables m_m_i and m_f_i
    };

    static const double m_m_i[ 10 ];    ///< [kg/kmol] molecular weight
    static const double m_f_i[ 10 ];    ///< [-] fractional volume

    static const double m_h_b[ 7 ];     ///< [m] altitude values
    static const double m_p_b[ 7 ];     ///< [Pa] pressure values
    static const double m_t_b[ 7 ];     ///< [K] temperature values
    static const double m_l_b[ 7 ];     ///< [K/m] temperature gradients

    static const double m_m;            ///< [kg/kmol] mean molecular weight
    static const double m_r;            ///< [N*m/(kmol*K)] gas constant
    static const double m_s;            ///< [K] Sutherland constant
    static const double m_beta;         ///< [kg/(s*m*K^0.5)] a constant used in computing dynamic viscosity
    static const double m_gamma;        ///< [-] a constant taken to represent the ratio of specific heat at constant pressure to the specific heat at constant volume

    static const double m_std_sl_t;     ///< [K]  standard sea level temperature (15 deg C)
    static const double m_std_sl_p;     ///< [Pa] standard sea level pressure (1013.25 hPa)

    /** Constructor. */
    Atmosphere();

    /** Destructor. */
    virtual ~Atmosphere();

    /**
     * Updates atmosphere due to altitude.
     * @param altitude [m] altitude above sea level
     */
    virtual void update( double altitude );

    /**
     * Sets sea level air pressure value.
     * @param slAirPressure [Pa] sea level air pressure
     */
    virtual void setPressureSL( double pressure_0 );

    /**
     * Sets sea level air temperature value.
     * @param slAirTemperature [K] sea level air temperature
     */
    virtual void setTemperatureSL( double temperature_0 );

    inline double getTemperature()  const { return m_temperature;  }
    inline double getPressure()     const { return m_pressure;     }
    inline double getDensity()      const { return m_density;      }
    inline double getSpeedOfSound() const { return m_speedOfSound; }
    inline double getDynViscosity() const { return m_dynViscosity; }
    inline double getKinViscosity() const { return m_kinViscosity; }

private:

    double m_temperature_0;     ///< [K] sea level air temperature
    double m_pressure_0;        ///< [Pa] sea level air pressure

    double m_temperature;       ///< [K] air temperature
    double m_pressure;          ///< [Pa] air static pressure
    double m_density;           ///< [kg/m^3] air density
    double m_speedOfSound;      ///< [m/s] speed of sound
    double m_dynViscosity;      ///< [Pa*s] dynamic viscosity
    double m_kinViscosity;      ///< [m^2/s] kinematic viscosity
};

} // end of fdm namespace

////////////////////////////////////////////////////////////////////////////////

#endif // FDM_ATMOSPHERE_H