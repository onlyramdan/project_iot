<?php
    include "connect.php";
    $suhu = isset($_POST['suhu']) ? $_POST["suhu"]: "";

    $sql = "INSERT INTO kondisi_air (suhu) VALUES ('".$suhu."');";
    $query = mysqli_query($conn, $sql);
    if(!$query){
        echo("Gagal Insert");
    }else{
        echo("Berhasil Insert");
    }
?>