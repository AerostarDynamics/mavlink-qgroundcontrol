/****************************************************************************
 *
 * Aerostar Dynamics branding for QGroundControl (UXV Navigator Tab5 build)
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "AerostarCorePlugin.h"

#include <QtCore/QApplicationStatic>

Q_APPLICATION_STATIC(AerostarCorePlugin, _aerostarCorePluginInstance);

AerostarCorePlugin::AerostarCorePlugin(QObject *parent)
    : QGCCorePlugin(parent)
{
}

QGCCorePlugin *AerostarCorePlugin::instance()
{
    return _aerostarCorePluginInstance();
}
