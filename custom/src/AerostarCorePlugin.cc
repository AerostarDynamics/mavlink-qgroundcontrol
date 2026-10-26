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
#ifdef Q_OS_ANDROID
#include <QtCore/QCoreApplication>
#include <QtCore/qcoreapplication_platform.h>
#include <QtCore/QTimer>
#endif

Q_APPLICATION_STATIC(AerostarCorePlugin, _aerostarCorePluginInstance);

AerostarCorePlugin::AerostarCorePlugin(QObject *parent)
    : QGCCorePlugin(parent)
{
}

QGCCorePlugin *AerostarCorePlugin::instance()
{
    return _aerostarCorePluginInstance();
}

void AerostarCorePlugin::init()
{
    QGCCorePlugin::init();

#ifdef Q_OS_ANDROID
    // Fast tablets (Galaxy Tab Active5) load QGC in about a second, so the Aerostar start-up screen was gone before
    // anyone saw it. Keep it up a little longer, then fade it out.
    static constexpr int kSplashExtraMs = 2500;
    static constexpr int kSplashFadeMs = 500;
    QTimer::singleShot(kSplashExtraMs, qApp, [] {
        QNativeInterface::QAndroidApplication::hideSplashScreen(kSplashFadeMs);
    });
#endif
}
