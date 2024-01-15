func isVowel(s byte) bool{  
	return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'
  }
  
  func maxVowels(s string, k int) int {
	vCnt := 0
	maxCnt := 0
	
	for i := 0; i < k; i++{
	  if(isVowel(s[i])){
		vCnt += 1
	  }
	}
	maxCnt = vCnt
	
	front := k
	for front < len(s){
	  if(isVowel((s[front]))){
		vCnt += 1
		}
	  if(isVowel((s[front - k]))){
		vCnt -= 1
	  }
	  if vCnt > maxCnt {
		maxCnt = vCnt
	  }
	  front += 1
	}

	return maxCnt
  }