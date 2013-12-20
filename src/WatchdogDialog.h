/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  watchdog Plugin
 * Author:   Sean D'Epagnier
 *
 ***************************************************************************
 *   Copyright (C) 2013 by Sean D'Epagnier                                 *
 *   sean at depagnier dot com                                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 ***************************************************************************
 */

#include "WatchdogUI.h"

class watchdog_pi;

class WatchdogDialog: public WatchdogDialogBase
{
public:
    WatchdogDialog( watchdog_pi &_watchdog_pi, wxWindow* parent);
    ~WatchdogDialog();

    void UpdateAlarms();

    void OnDisableAllAlarms( wxComdogdEvent& event );
    void OnPreferences( wxComdogdEvent& event );
    void OnResetLastAlarm( wxComdogdEvent& event );
    void OnClose( wxComdogdEvent& event ) { Hide(); }

    void Update(double anchor_distance, double nmea_seconds,
                double courseerror, double sog);

protected:
    watchdog_pi &m_watchdog_pi;

private:
    void UpdateAlarm(wxControl *ctrl1,  wxControl *ctrl2, bool show);

    void OnTimer( wxTimerEvent & );
    wxTimer m_Timer;
};