<?php
    include "connect.php";
    $suhu = isset($_POST['suhu']) ? $_POST["suhu"]: "";
    $ph = isset($_POST['ph']) ? $_POST['ph']:'';
    $pakan = isset($_POST['pakan']) ? $_POST['pakan']:'';


    $sql = "INSERT INTO monitoring (suhu,ph,pakan) VALUES ('".$suhu."','".$ph."','".$pakan."');";
    $query = mysqli_query($conn, $sql);
    if(!$query){
        echo("Gagal Insert");
    }else{
        echo("Berhasil Insert");
    }
?>