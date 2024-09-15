
# Test Specification for Soundex Program

---

### Test Suite 1: generatesCorrectSoundexCode

**Purpose**: Verify that the function generates the correct Soundex code for a variety of names.

1. **Test Case ID**: TC-01  
   **Name Input**: Robert  
   **Expected Soundex Code**: R163  
   **Description**: Common name, checks conversion of 'b' and 'r'.  

2. **Test Case ID**: TC-02  
   **Name Input**: Rupert  
   **Expected Soundex Code**: R163  
   **Description**: Tests similar-sounding names, checks consistency with `TC-01`.  

3. **Test Case ID**: TC-03  
   **Name Input**: Rubin  
   **Expected Soundex Code**: R150  
   **Description**: Another name, tests different conversion for 'n'.  

4. **Test Case ID**: TC-04  
   **Name Input**: Aeiouhw  
   **Expected Soundex Code**: A000  
   **Description**: Tests ignoring of vowels and 'h', 'w'.  

5. **Test Case ID**: TC-05  
   **Name Input**: Ashcroft  
   **Expected Soundex Code**: A261  
   **Description**: Tests multiple conversions and ignoring vowels.  

6. **Test Case ID**: TC-06  
   **Name Input**: Pfister  
   **Expected Soundex Code**: P236  
   **Description**: Tests 'P' followed by 'f' without duplication.  

7. **Test Case ID**: TC-07  
   **Name Input**: Honeyman  
   **Expected Soundex Code**: H555  
   **Description**: Tests multiple 'n' characters with expected '5' result.  

---

### Test Suite 2: returnsEmptyForEmptyString

**Purpose**: Verify that the function correctly handles empty string input.

1. **Test Case ID**: TC-08  
   **Name Input**: "" (Empty string)  
   **Expected Soundex Code**: ""  
   **Description**: Empty string should return empty Soundex code.  

---

### Test Suite 3: padsShortNamesWithZeros

**Purpose**: Verify that the function pads names shorter than 4 characters with zeros.

1. **Test Case ID**: TC-09  
   **Name Input**: Ra  
   **Expected Soundex Code**: R000  
   **Description**: Short name should be padded to 4 characters.  

2. **Test Case ID**: TC-10  
   **Name Input**: R  
   **Expected Soundex Code**: R000  
   **Description**: Single letter should be padded with three zeros.  

---

### Test Suite 4: returnsSameSoundexForUpperAndLowerCase

**Purpose**: Verify that the Soundex function produces identical results for both uppercase and lowercase input strings

1. **Test Case ID**: TC-11  
   **Name Input 1**: Rupert  
   **Name Input 2**: RUPERT  
   **Expected Result**: Both inputs should generate the same Soundex code.  
   **Description**: Both lowercase and uppercase should return the same Soundex code.  

2. **Test Case ID**: TC-12  
   **Name Input 1**: Rubin  
   **Name Input 2**: RUBIN  
   **Expected Result**: Both inputs should generate the same Soundex code.  
   **Description**: Both lowercase and uppercase should return the same Soundex code.  
