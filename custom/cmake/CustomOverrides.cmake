# Aerostar Dynamics build of QGroundControl for the UXV Navigator Tab5 (Samsung Galaxy Tab Active5)
# talking to the aircraft over a Doodle Labs Mesh Rider Mini (MAVLink over UDP, video over RTSP).

set(QGC_APP_DESCRIPTION "Aerostar GCS")
set(QGC_APP_COPYRIGHT "Copyright (C) 2026 Aerostar Dynamics. Based on QGroundControl, Copyright (C) Dronecode Project.")
set(QGC_ORG_NAME "Aerostar Dynamics")
set(QGC_ORG_DOMAIN "aerostardynamics.com")

# Own app id, so it installs next to (and never clashes with) QGroundControl from the Play Store
set(QGC_PACKAGE_NAME "com.aerostardynamics.qgroundcontrol")
set(QGC_ANDROID_PACKAGE_NAME "${QGC_PACKAGE_NAME}")
