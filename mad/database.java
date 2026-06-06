/*
--- activity_main.xml ---
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:tools="http://schemas.android.com/tools"
 android:id="@+id/activity_main"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 android:padding="16dp"
 tools:context="com.example.exercise4.MainActivity"
 android:orientation="vertical">

 <EditText
 android:id="@+id/et_name"
 android:layout_width="match_parent"
 android:layout_height="wrap_content"
 android:hint="Enter name"
 android:inputType="textPersonName"
 android:autofillHints="name"/>

 <EditText
 android:id="@+id/et_age"
 android:layout_width="match_parent"
 android:layout_height="wrap_content"
 android:inputType="numberDecimal"
 android:hint="Enter age"
 android:autofillHints="age"/>

 <Button
 android:id="@+id/btn_submit"
 android:layout_width="match_parent"
 android:layout_height="wrap_content"
 android:text="@string/submit" />

 <Button
 android:id="@+id/btn_view_all"
 android:layout_width="match_parent"
 android:layout_height="wrap_content"
 android:text="View All" />

 <TextView
 android:id="@+id/tv_user_data"
 android:layout_width="match_parent"
 android:layout_height="wrap_content"
 android:padding="16dp"
 android:textSize="16sp"
 android:textStyle="bold" />

</LinearLayout>
*/

package com.example.exercise4;

import androidx.appcompat.app.AppCompatActivity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
 private EditText etName, etAge;
 private SQLiteDatabase db;
 private TextView tvUserData;

 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);

 etName = findViewById(R.id.et_name);
 etAge = findViewById(R.id.et_age);
 Button btnSubmit = findViewById(R.id.btn_submit);
 Button btnViewAll = findViewById(R.id.btn_view_all);
 tvUserData = findViewById(R.id.tv_user_data);

 db = openOrCreateDatabase("UserDB", MODE_PRIVATE, null);
 db.execSQL("CREATE TABLE IF NOT EXISTS users(name VARCHAR, age INT)");

 btnSubmit.setOnClickListener(view -> {
 String name = etName.getText().toString().trim();
 String ageStr = etAge.getText().toString().trim();
 if (name.isEmpty() || ageStr.isEmpty()) {
 Toast.makeText(MainActivity.this, "Please enter both name and age", Toast.LENGTH_SHORT).show();
 return;
 }
 int age = Integer.parseInt(ageStr);
 ContentValues values = new ContentValues();
 values.put("name", name);
 values.put("age", age);
 db.insert("users", null, values);
 Toast.makeText(MainActivity.this, "User added successfully", Toast.LENGTH_SHORT).show();
 etName.setText("");
 etAge.setText("");
 });

 btnViewAll.setOnClickListener(view -> {
 Cursor cursor = db.rawQuery("SELECT * FROM users", null);
 StringBuilder sb = new StringBuilder();
 if (cursor.moveToFirst()) {
 do {
 String name = cursor.getString(cursor.getColumnIndexOrThrow("name"));
 int age = cursor.getInt(cursor.getColumnIndexOrThrow("age"));
 sb.append("Name: ").append(name).append(", Age: ").append(age).append("\n");
 } while (cursor.moveToNext());
 }
 cursor.close();
 if (sb.length() == 0) {
 tvUserData.setText(R.string.no_user);
 }
 else {
 tvUserData.setText(sb.toString());
 }
 });
 }

 @Override
 protected void onDestroy() {
 super.onDestroy();
 db.close();
 }
}
