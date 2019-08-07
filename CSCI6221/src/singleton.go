/*  Author: Team 2- Steven Williams & Fadi Dagher
**  Class: CSCI 6221
**  Purpose: Implement the best practice of "Double Checked Locking" for thread safety and minimal locking. 
*/

package main

import "sync"
import "fmt"

//Singleton "class" with a string for output
type singleton struct {
    sampleString string
}

//Create instance of Singleton
var instanceSingleton *singleton

//Lock method 
var mutex sync.Mutex

func GetInstance(sampleS string) *singleton {
    //Only initiate lock if object is null
    if instanceSingleton == nil {    
        
        //Make thread safe
        mutex.Lock()
        defer mutex.Unlock()

        //Check again as multiple threads can reach this step
        if instanceSingleton == nil {
            instanceSingleton = &singleton{sampleS}
        }
    }
    //Return object
    return instanceSingleton
}

func main(){
    //Should instantiate per usual
    var instance1 = GetInstance("1st instance of singleton.")
    fmt.Println(instance1.sampleString) 

    //Should not instatiate, return the string for instance1
    var instance2 = GetInstance("2nd instance of singleton.")
    fmt.Println(instance2.sampleString) 
}