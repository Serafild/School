<?php
if(isset($_POST['username'])){
    if($_POST['password'] === $_POST['passwordconfirmation']){
        include_once 'lib/Database_Manager.php';
        $database = new DatabaseManager('unity');
        $query = "INSERT INTO unity.user VALUES(NULL,
                                                '" . $_POST['username'] . "',
                                                '" . md5($_POST['password']) . "',
                                                0)";
        $database->FetchDatabase($query);
    }
}

header('location: /api');
?>