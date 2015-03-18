<?php

require_once "Class.Database.inc";
require_once "Class.Address.inc";


/**
 * Create with default information
 */
$address = new Address(
    array(
        "name"=>"mohammad",
        "street"=>"25 South Street",
        "ssn" =>"2222"
        )
);


/**
 * print address
 */
echo $address->dispaly();

/**
 * set variable
 */
$address->__set("name","John");

/**
 * save to database
 */
$address->saveNametoDB("Sarah");
