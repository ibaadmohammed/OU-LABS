/*
--- AndroidManifest.xml ---
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:tools="http://schemas.android.com/tools">

 <uses-permission android:name="android.permission.POST_NOTIFICATIONS" />

 <application
 android:allowBackup="true"
 android:dataExtractionRules="@xml/data_extraction_rules"
 android:fullBackupContent="@xml/backup_rules"
 android:icon="@mipmap/ic_launcher"
 android:label="@string/app_name"
 android:supportsRtl="true"
 android:theme="@style/Theme.Exercise5"
 tools:targetApi="31">
 <activity
 android:name=".MainActivity"
 android:exported="true">
 <intent-filter>
 <action android:name="android.intent.action.MAIN" />
 <category android:name="android.intent.category.LAUNCHER" />
 </intent-filter>
 </activity>
 </application>

</manifest>
*/

package com.example.exercise5;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.NotificationCompat;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.content.Context;
import android.os.Build;
import android.os.Bundle;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class MainActivity extends AppCompatActivity {
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);
 showCurrentTime();
 }

 private void showCurrentTime() {
 Calendar calendar = Calendar.getInstance();
 SimpleDateFormat simpleDateFormat = new SimpleDateFormat("hh:mm:ss a");
 String currentTime = simpleDateFormat.format(calendar.getTime());
 displayNotification(currentTime);
 }

 private void displayNotification(String content) {
 NotificationManager notificationManager =
 (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
 if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
 NotificationChannel notificationChannel =
 new NotificationChannel("default", "Channel name",
 NotificationManager.IMPORTANCE_DEFAULT);
 notificationManager.createNotificationChannel(notificationChannel);
 }
 NotificationCompat.Builder builder =
 new NotificationCompat.Builder(this, "default")
 .setSmallIcon(R.drawable.ic_launcher_foreground)
 .setContentTitle("Current Time")
 .setContentText(content)
 .setPriority(NotificationCompat.PRIORITY_DEFAULT);
 notificationManager.notify(1, builder.build());
 }
}
