func isVowel(s string) bool{
	vowels := []string{"a", "e", "i", "o", "u"}
  
	for _, letter := range vowels{
	  if(s == letter){
		return true
	  }
	}
	return false
  }
  
  func maxVowels(s string, k int) int {
	vCnt := 0
	maxCnt := 0
	
	for i := 0; i < k; i++{
	  if(isVowel(string(s[i]))){
		vCnt += 1
	  }
	}
	maxCnt = vCnt
  
	front := k
	back := 0
	for front < len(s){
	  if(isVowel(string(s[front]))){
		vCnt += 1
		}
	  if(isVowel(string(s[back]))){
		vCnt -= 1
	  }
	  if vCnt > maxCnt {
		maxCnt = vCnt
	  }
	  
	  front += 1
	  back += 1
	  
	}
	return maxCnt
  }