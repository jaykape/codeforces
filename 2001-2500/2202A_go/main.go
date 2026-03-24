package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)

	for t > 0 {
		t--

		var x, y int
		fmt.Fscan(in, &x, &y)

		if (x/2 >= y && y >= -x/4) && ((x+y)%3 == 0) {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}

	}
}
