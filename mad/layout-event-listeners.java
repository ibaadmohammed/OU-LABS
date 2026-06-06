/*
--- activity_main.xml ---
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 tools:context=".MainActivity">

 <LinearLayout
 android:layout_width="match_parent"
 android:layout_height="100dp">

 <TextView
 android:id="@+id/textView"
 android:layout_width="match_parent"
 android:layout_height="wrap_content"
 android:layout_margin="30dp"
 android:text="Details Form"
 android:textSize="25sp"
 android:gravity="center"/>

 </LinearLayout>

 <GridLayout
 android:id="@+id/gridLayout"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 android:layout_marginTop="100dp"
 android:layout_marginBottom="200dp"
 android:columnCount="2"
 android:rowCount="3">

 <TextView
 android:id="@+id/textView1"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_margin="10dp"
 android:layout_row="0"
 android:layout_column="0"
 android:text="Name"
 android:textSize="20sp"
 android:gravity="center"/>

 <EditText
 android:id="@+id/editText"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_margin="10dp"
 android:layout_row="0"
 android:layout_column="1"
 android:ems="10"/>

 <TextView
 android:id="@+id/textView2"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_margin="10dp"
 android:layout_row="1"
 android:layout_column="0"
 android:text="Reg.No"
 android:textSize="20sp"
 android:gravity="center"/>

 <EditText
 android:id="@+id/editText2"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_margin="10dp"
 android:layout_row="1"
 android:layout_column="1"
 android:inputType="number"
 android:ems="10"/>

 <TextView
 android:id="@+id/textView3"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_margin="10dp"
 android:layout_row="2"
 android:layout_column="0"
 android:text="Dept"
 android:textSize="20sp"
 android:gravity="center"/>

 <Spinner
 android:id="@+id/spinner"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_margin="10dp"
 android:layout_row="2"
 android:layout_column="1"
 android:spinnerMode="dropdown"/>

 </GridLayout>

 <Button
 android:id="@+id/button"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentBottom="true"
 android:layout_centerInParent="true"
 android:layout_marginBottom="150dp"
 android:text="Submit"/>

</RelativeLayout>

--- activity_second.xml ---
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 tools:context="SecondActivity"
 android:orientation="vertical"
 android:gravity="center">

 <TextView
 android:id="@+id/textView1"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_margin="20dp"
 android:text="New Text"
 android:textSize="30sp"/>

 <TextView
 android:id="@+id/textView2"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_margin="20dp"
 android:text="New Text"
 android:textSize="30sp"/>

 <TextView
 android:id="@+id/textView3"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_margin="20dp"
 android:text="New Text"
 android:textSize="30sp"/>

</LinearLayout>

--- SecondActivity.java ---
package com.example.exercise2;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.content.Intent;
import android.widget.TextView;

public class SecondActivity extends AppCompatActivity {
 TextView t1,t2,t3;
 String name,reg,dept;

 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_second);

 t1= (TextView) findViewById(R.id.textView1);
 t2= (TextView) findViewById(R.id.textView2);
 t3= (TextView) findViewById(R.id.textView3);

 Intent i = getIntent();
 name=i.getStringExtra("name_key");
 reg=i.getStringExtra("reg_key");
 dept=i.getStringExtra("dept_key");

 t1.setText(name);
 t2.setText(reg);
 t3.setText(dept);
 }
}
*/

package com.example.exercise2;

import androidx.appcompat.app.AppCompatActivity;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.os.Bundle;
import android.content.Intent;

public class MainActivity extends AppCompatActivity {
 EditText e1,e2;
 Button bt;
 Spinner s;
 String [] dept_array={"CSE","ECE","IT","Mech","Civil"};
 String name,reg,dept;

 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);

 e1= (EditText) findViewById(R.id.editText);
 e2= (EditText) findViewById(R.id.editText2);
 bt= (Button) findViewById(R.id.button);
 s= (Spinner) findViewById(R.id.spinner);

 ArrayAdapter adapter= new ArrayAdapter(MainActivity.this,android.R.layout.simple_spinner_item,dept_array);
 s.setAdapter(adapter);

 bt.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View v) {
 name=e1.getText().toString();
 reg=e2.getText().toString();
 dept=s.getSelectedItem().toString();

 Intent i = new Intent(MainActivity.this,SecondActivity.class);
 i.putExtra("name_key", name);
 i.putExtra("reg_key",reg);
 i.putExtra("dept_key", dept);
 startActivity(i);
 }
 });
 }
}
