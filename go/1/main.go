package main

import (
	"fmt"
)

func main() {
	fmt.Printf("Hello\n")
	total := 0

	for i := 3; i < 1000; i += 3 {
		total += i
	}
	for i := 5; i < 1000; i += 5 {
		if i%3 != 0 {
			total += i
		}
	}
	fmt.Printf("%d\n", total)

}
