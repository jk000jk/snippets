<?php
$con = mysqli_connect("localhost", "id5774869_root", "password", "id5774869_student");
if (mysqli_connect_errno()) {
    echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
mysqli_select_db($con, "id5774869_student");
$cuvant_ro = $_POST['cuv'];
$del = "DELETE FROM dictionar WHERE cuvant_ro='$cuvant_ro';";
if (mysqli_query($con, $del)) {
    echo "Stergerea s-a realizat cu succes.";
} else {
    echo "Stergereaza nu s-a putut realiza " . mysqli_connect_error();
}
?>
