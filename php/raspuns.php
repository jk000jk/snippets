<?php
$rasp = $_POST['r'];
if ((strtoupper($rasp)) == 'D') {
    include "index.html";
} else {
    include "meniu.html";
}
?>
