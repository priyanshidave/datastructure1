<HTML>
<?php
    #calculate 60 days in the future: seconds * minutes * hours * days + current time
    date_default_timezone_set("Asia/Calcutta");
    $itm=60*60*24*60+time();
    ECHO "<BR>";

    $curr = date("h:i:s - m/d/y",time());
    echo $curr;ECHO "<BR>";
    #create cookie
    setcookie('last_visit',date("i:s - m/d/y"),$itm);
    #check if cookie exists
   if(isset($_COOKIE['last_visit'])) 
   {
        $visit=$_COOKIE['last_visit'];
        echo "Your last visit was- " .$visit;
    }
    else 
    {
        #no cookies
       echo "You have some stale cookies!" ;
    }
 ?>
</HTML>