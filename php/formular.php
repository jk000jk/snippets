<?php
$con = mysqli_connect("localhost", "id5774869_root", "password", "id5774869_student");
if (mysqli_connect_errno()) {
    echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
mysqli_select_db($con, "id5774869_student");
$c_ro = $_POST['c_ro'];
$c_en = $_POST['c_en'];

$a = "INSERT INTO dictionar (cuvant_ro, cuvant_en) VALUES ('$c_ro','$c_en');";
if (mysqli_query($con, $a)) {
    echo "datele au fost introduse";
} else {
    echo "Failed to con to MySQL: " . mysqli_connect_error();
}
echo "
        <form name='a' method='post' action ='raspuns.php'>
            continuati:<input type='text' name='r' size='1' value='d' /><b>da/nu</b>
            <input type='submit' value='trimite' />
        </form>
    ";
?>
