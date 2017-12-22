<?php
function generateToken(){
    $hash = md5(rand());
    return $hash;
}
?>