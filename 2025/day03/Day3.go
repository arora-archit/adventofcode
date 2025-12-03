package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	total :=0
	for scanner.Scan() {
		line := scanner.Text()
		n := len(line)
		k := 12
		result := make([]byte, 0,20)
		start := 0
		for k > 0 {
			maxDigit := -1
			maxIndex := start
			end := n - k
			for i := start; i <= end; i++ {
				d := int(line[i] - '0')
				if d > maxDigit {
					maxDigit = d
					maxIndex = i
				}
			}
			result = append(result, byte(maxDigit)+'0')
			start = maxIndex + 1
			k--
		}
		val, err := strconv.Atoi(string(result))
		if err != nil {
			panic(err)
		}
		total += val
	}
	fmt.Println(total)
}