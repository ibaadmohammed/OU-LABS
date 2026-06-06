import android.widget.TextView;
import android.view.Gravity;
import java.text.SimpleDateFormat;
import java.util.Calendar;

String date = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(Calendar.getInstance().getTime());

TextView txtView = new TextView(this);
txtView.setText("Current Date and time : "+date);
txtView.setGravity(Gravity.CENTER);
txtView.setTextSize(20);
setContentView(txtView);
