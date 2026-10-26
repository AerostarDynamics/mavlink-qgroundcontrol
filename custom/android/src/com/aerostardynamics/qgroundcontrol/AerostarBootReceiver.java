package com.aerostardynamics.qgroundcontrol;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.provider.Settings;
import android.util.Log;

/**
 * Aerostar: start Aerostar GCS when the tablet finishes booting (UXV Navigator Tab5 field use).
 *
 * Android 10+ only lets an app open its screen from the background if it holds the "Appear on top"
 * (SYSTEM_ALERT_WINDOW) permission. A technician grants it once per tablet:
 * Settings > Apps > Aerostar GCS > Appear on top. Without it the app simply does not auto-start.
 */
public class AerostarBootReceiver extends BroadcastReceiver {
    private static final String TAG = "AerostarBootReceiver";
    private static final String ACTION_QUICKBOOT_POWERON = "android.intent.action.QUICKBOOT_POWERON";

    @Override
    public void onReceive(Context context, Intent intent) {
        final String action = intent.getAction();
        if (!Intent.ACTION_BOOT_COMPLETED.equals(action) && !ACTION_QUICKBOOT_POWERON.equals(action)) {
            return;
        }

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M && !Settings.canDrawOverlays(context)) {
            Log.w(TAG, "Not auto-starting: 'Appear on top' permission has not been granted");
            return;
        }

        final Intent launch = context.getPackageManager().getLaunchIntentForPackage(context.getPackageName());
        if (launch == null) {
            Log.w(TAG, "Not auto-starting: no launch intent");
            return;
        }
        launch.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        context.startActivity(launch);
    }
}
