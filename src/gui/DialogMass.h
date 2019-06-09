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
#ifndef DIALOGMASS_H
#define DIALOGMASS_H

////////////////////////////////////////////////////////////////////////////////

#include <QDialog>
#include <QSettings>

////////////////////////////////////////////////////////////////////////////////

namespace Ui
{
    class DialogMass;
}

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief This is 'Fuel and Payload' dialog class.
 */
class DialogMass : public QDialog
{
    Q_OBJECT

public:

    /** Constructor. */
    explicit DialogMass( QWidget *parent = 0 );
    
    /** Destructor. */
    virtual ~DialogMass();

    void readData();
    void saveData();

    inline double getPilot1() const { return m_pilot_1; }
    inline double getPilot2() const { return m_pilot_2; }

    inline double getFuelTank1() const { return m_fuel_tank_1; }
    inline double getFuelTank2() const { return m_fuel_tank_2; }
    inline double getFuelTank3() const { return m_fuel_tank_3; }
    inline double getFuelTank4() const { return m_fuel_tank_4; }

    inline double getCabin()  const { return m_cabin; }
    inline double getTrunk()  const { return m_trunk; }

    void setAircraftType( int type );

private:

    Ui::DialogMass *m_ui;

    int m_type;

    double m_pilot_1;       ///< [kg]
    double m_pilot_2;       ///< [kg]

    double m_fuel_tank_1;   ///< [kg]
    double m_fuel_tank_2;   ///< [kg]
    double m_fuel_tank_3;   ///< [kg]
    double m_fuel_tank_4;   ///< [kg]

    double m_cabin;         ///< [kg]
    double m_trunk;         ///< [kg]

    void settingsRead();
    void settingsRead_MassData( QSettings &settings );
    void settingsRead_UnitCombos( QSettings &settings );

    void settingsSave();
    void settingsSave_MassData( QSettings &settings );
    void settingsSave_UnitCombos( QSettings &settings );

private slots:

    void on_comboBoxPilot_1_currentIndexChanged( int index );
    void on_comboBoxPilot_2_currentIndexChanged( int index );

    void on_comboBoxFuelTank_1_currentIndexChanged( int index );
    void on_comboBoxFuelTank_2_currentIndexChanged( int index );
    void on_comboBoxFuelTank_3_currentIndexChanged( int index );
    void on_comboBoxFuelTank_4_currentIndexChanged( int index );

    void on_comboBoxCabin_currentIndexChanged( int index );
    void on_comboBoxTrunk_currentIndexChanged( int index );
};

////////////////////////////////////////////////////////////////////////////////

#endif // DIALOGMASS_H
