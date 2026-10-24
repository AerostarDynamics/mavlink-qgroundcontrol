/****************************************************************************
 *
 * Aerostar Dynamics branding for QGroundControl (UXV Navigator Tab5 build)
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "QGCCorePlugin.h"

class AerostarCorePlugin : public QGCCorePlugin
{
    Q_OBJECT

public:
    explicit AerostarCorePlugin(QObject *parent = nullptr);

    static QGCCorePlugin *instance();

    // Aerostar logo in the fly-view toolbar: white lettering for the dark (indoor) palette, black for the light one
    QString brandImageIndoor() const override { return QStringLiteral("/custom/img/AerostarLogoWhite.png"); }
    QString brandImageOutdoor() const override { return QStringLiteral("/custom/img/AerostarLogoBlack.png"); }
};
