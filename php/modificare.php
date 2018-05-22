<?php
$con = mysqli_connect("localhost", "id5774869_root", "password", "id5774869_student");
if (mysqli_connect_errno()) {
    echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
mysqli_select_db($con, "id5774869_student");
$id = $_POST['id'];
$cv_ro = $_POST['cuv'];
$sql = "UPDATE dictionar SET cuvant_ro='$cv_ro' WHERE id=$id";
$x = "SELECT * FROM dictionar LIMIT 200;";
if (mysqli_query($con, $sql)) {
    echo "Afisarea!";
} else {
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}
$y = mysqli_query($con, $x);
echo "<table border='1' bgcolor='B0E0E6'>Ω
	  <tr>
	  <td><b>Id</b></td>
	  <td><b>Cuvant_ro</b></td>
	  <td><b>Cuvant_en</b></td>
	  </tr>";
while ($z = mysqli_fetch_assoc($y)) {
    echo "<tr bgcolor='C0C0C0'>
		  <td>" . $z["id"] . "</td>
		  <td>" . $z["cuvant_ro"] . "</td>
			<td>" . $z["cuvant_en"] . "</td></tr>    ";
}
echo "</table>";
?>
