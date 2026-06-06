/*
--- activity_main.xml ---
<?xml version="1.0" encoding="utf-8"?>
<!-- Relative Layout -->
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
 xmlns:tools="http://schemas.android.com/tools"
 android:layout_width="match_parent"
 android:layout_height="match_parent"
 tools:context=".MainActivity">

 <!-- Edit text for email id -->
 <EditText
 android:id="@+id/editText1"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignParentTop="true"
 android:layout_alignParentRight="true"
 android:layout_marginTop="18dp"
 android:layout_marginRight="22dp" />

 <!-- Edit text for email subject -->
 <EditText
 android:id="@+id/editText2"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_below="@+id/editText1"
 android:layout_alignLeft="@+id/editText1"
 android:layout_marginTop="20dp" />

 <!-- Edit text for email body -->
 <EditText
 android:id="@+id/editText3"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_below="@+id/editText2"
 android:layout_alignLeft="@+id/editText2"
 android:layout_marginTop="30dp" />

 <!-- text Views for label -->
 <TextView
 android:id="@+id/textView1"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignBaseline="@+id/editText1"
 android:layout_alignBottom="@+id/editText1"
 android:layout_alignParentLeft="true"
 android:text="Send To:"
 android:textColor="#0F9D58" />

 <TextView
 android:id="@+id/textView2"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignBaseline="@+id/editText2"
 android:layout_alignBottom="@+id/editText2"
 android:layout_alignParentLeft="true"
 android:text="Email Subject:"
 android:textColor="#0F9D58" />

 <TextView
 android:id="@+id/textView3"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_alignBaseline="@+id/editText3"
 android:layout_alignBottom="@+id/editText3"
 android:text="Email Body:"
 android:textColor="#0F9D58" />

 <!-- Button to send email -->
 <Button
 android:id="@+id/button"
 android:layout_width="wrap_content"
 android:layout_height="wrap_content"
 android:layout_below="@+id/editText3"
 android:layout_alignLeft="@+id/editText3"
 android:layout_marginLeft="76dp"
 android:layout_marginTop="20dp"
 android:text="Send email!!" />

</RelativeLayout>
*/

package com.example.exercise11;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.content.Intent;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {
 Button button;
 EditText sendto, subject, body;

 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);

 sendto = findViewById(R.id.editText1);
 subject = findViewById(R.id.editText2);
 body = findViewById(R.id.editText3);
 button = findViewById(R.id.button);

 button.setOnClickListener(view -> {
 String emailsend = sendto.getText().toString();
 String emailsubject = subject.getText().toString();
 String emailbody = body.getText().toString();

 Intent intent = new Intent(Intent.ACTION_SEND);
 intent.putExtra(Intent.EXTRA_EMAIL, new String[]{emailsend});
 intent.putExtra(Intent.EXTRA_SUBJECT, emailsubject);
 intent.putExtra(Intent.EXTRA_TEXT, emailbody);
 intent.setType("message/rfc822");
 startActivity(Intent.createChooser(intent, "Choose an Email client :"));
 });
 }
}
