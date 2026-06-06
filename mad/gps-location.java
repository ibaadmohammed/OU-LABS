/*
--- AndroidManifest.xml ---
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:tools="http://schemas.android.com/tools">

 <uses-permission android:name="android.permission.ACCESS_FINE_LOCATION" />
 <uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION" />

 <application
 android:allowBackup="true"
 android:dataExtractionRules="@xml/data_extraction_rules"
 android:fullBackupContent="@xml/backup_rules"
 android:icon="@mipmap/ic_launcher"
 android:label="@string/app_name"
 android:supportsRtl="true"
 android:theme="@style/Theme.Exercise7"
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

package com.example.exercise7;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.Manifest;
import android.content.pm.PackageManager;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

public class MainActivity extends AppCompatActivity {
 private static final int PERMISSION_REQUEST_CODE = 1;
 private LocationManager locationManager;
 private LocationListener locationListener;

 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);

 locationManager = (LocationManager) getSystemService(LOCATION_SERVICE);

 locationListener = new LocationListener() {
 @Override
 public void onLocationChanged(Location location) {
 Toast.makeText(MainActivity.this, "Latitude: " + location.getLatitude() + " Longitude: " + location.getLongitude(), Toast.LENGTH_SHORT).show();
 }
 @Override
 public void onStatusChanged(String provider, int status, Bundle extras) {}
 @Override
 public void onProviderEnabled(String provider) {}
 @Override
 public void onProviderDisabled(String provider) {}
 };

 if (ContextCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED
 && ContextCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
 ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.ACCESS_FINE_LOCATION,
 Manifest.permission.ACCESS_COARSE_LOCATION}, PERMISSION_REQUEST_CODE);
 } else {
 locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 0, 0, locationListener);
 }
 }

 @Override
 public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
 if (requestCode == PERMISSION_REQUEST_CODE) {
 if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
 if (ContextCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED
 && ContextCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
 locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 0, 0, locationListener);
 }
 } else {
 Toast.makeText(this, "Location permission denied", Toast.LENGTH_SHORT).show();
 }
 }
 }

 @Override
 protected void onDestroy() {
 super.onDestroy();
 if (locationManager != null) {
 locationManager.removeUpdates(locationListener);
 }
 }
}
