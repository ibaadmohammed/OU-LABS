/*
--- activity_main.xml ---
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 tools:context=".MainActivity">

 <TextView
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_marginTop="180dp"
 android:gravity="center_horizontal"
 android:text="Press The Back Button of Your Phone."
 android:textSize="30dp"
 android:textStyle="bold" />

</RelativeLayout>
*/

package com.example.exercise9;

import android.content.DialogInterface;
import android.os.Bundle;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);
 }

 @Override
 public void onBackPressed() {
 AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
 builder.setMessage("Do you want to exit ?");
 builder.setTitle("Alert !");
 builder.setCancelable(false);

 builder.setPositiveButton("Yes", (DialogInterface.OnClickListener) (dialog, which) -> {
 finish();
 });

 builder.setNegativeButton("No", (DialogInterface.OnClickListener) (dialog, which) -> {
 dialog.cancel();
 });

 AlertDialog alertDialog = builder.create();
 alertDialog.show();
 }
}
