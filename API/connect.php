<?php 
$hostname = "localhost";
$username = "root";
$pass = "";
$database ="leleIot";

$conn = mysqli_connect($hostname,$username,$pass,$database);

if(!$conn){
    die("Koneksi gagal:" .mysqli_connect_error());
};
?>