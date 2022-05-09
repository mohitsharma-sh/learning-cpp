#include "regex.h"
#include <iostream>


/* Initialize the regex operator to apply exactly once. */
RegexOperator::RegexOperator() {
    minRepeat = 1;
    maxRepeat = 1;
}


/* Returns the "minimum repeat count" value. */
int RegexOperator::getMinRepeat() const {
    return minRepeat;
}


/* Returns the "maximum repeat count" value. */
int RegexOperator::getMaxRepeat() const {
    return maxRepeat;
}


/* Sets the "minimum repeat count" value. */
void RegexOperator::setMinRepeat(int n) {
    assert(n >= 0);
    minRepeat = n;
}


/* Sets the "maximum repeat count" value. */
void RegexOperator::setMaxRepeat(int n) {
    assert(n >= -1);
    maxRepeat = n;
}


/* Clears the list of matches stored in the regex operator.  Typically done
 * in preparation to try to match the regex to a new string.
 */
void RegexOperator::clearMatches() {
    matches.clear();
}


/* Records a new match of the operator in the list of matches. */
void RegexOperator::pushMatch(const Range &r) {
    matches.push_back(r);
}


/* Reports how many times the regex operator has successfully matched in the
 * string.
 */
int RegexOperator::numMatches() const {
    return (int) matches.size();
}


/* Removes the last match the operator successfully matched against.  Used for
 * backtracking by the regex engine.
 */
Range RegexOperator::popMatch() {
    Range r = matches.back();
    matches.pop_back();
    return r;
}


/* Initialize MatchChar regex operator to match to a specific character */
MatchChar::MatchChar(char c): matchedChar(c) {}

/* Match against a specific character. */
bool MatchChar::match(string const& s, Range& r) const {
    int start = r.start;
    bool retVal = false;
    if (start < s.length() && s[start] == matchedChar) {
        r.end += 1;
        retVal = true;
    }
    
    return retVal;
}

/* Match against any character. */
bool MatchAny::match(string const& s, Range& r) const {
    bool retVal = false;
    if (r.start < s.length()) {
        r.end += 1;
        retVal = true;
    }

    return retVal;
}

/* Initialize MatchFromSubset with a set of characters specified as string. */
MatchFromSubset::MatchFromSubset(string const& subset_): subset(subset_) {};

/* Match against a character from the provided set. */
bool MatchFromSubset::match(string const& s, Range& r) const{
    bool retVal = false;

    if (r.start < s.length() && subset.find(s[r.start]) != string::npos) {
        r.end += 1;
        retVal = true;
    }

    return retVal;
}

/* Initialize with excluded characters from a match. */
ExcludeFromSubset::ExcludeFromSubset(string const& subset_): subset(subset_) {}

/* Match against characters excluded through the provided set. */
bool ExcludeFromSubset::match(string const& s, Range& r) const {
    bool retVal = false;

    if (r.start < s.length() && subset.find(s[r.start]) == string::npos) {
        r.end += 1;
        retVal = true;
    }

    return retVal;
}

vector<RegexOperator* > parseRegex(string const& expr) {
    vector<RegexOperator*> regexOps;
    
    RegexOperator* newOp = nullptr;
    auto it = expr.begin();

    while (it != expr.end()) {
        auto nextIt = it + 1;

        int minRepeat, maxRepeat;
        char currChar = *it;

        
        if (currChar == '\\') {
            ++it;
            newOp = new MatchChar(*it);
            nextIt = it + 1;
        }
        else if (currChar == '[') {
            auto endIt = it;

            while (*endIt != ']') {
                ++endIt;
            }
            if (*nextIt == '^') {
                newOp = new ExcludeFromSubset(string(nextIt + 1, endIt));
            } 
            else {
                newOp = new MatchFromSubset(string(nextIt, endIt));
            }
            it = endIt;
            nextIt = it + 1;
        }
        else if (currChar == '.') {
            newOp = new MatchAny();
        }
        else {
            newOp = new MatchChar(currChar);
        }

        // Infer Repeats
        if (*nextIt == '*') {
            ++it;
            minRepeat = 0; maxRepeat = -1;
        }
        else if (*nextIt == '+') {
            ++it;
            minRepeat = 1; maxRepeat = -1;
        }
        else if (*nextIt == '?') {
            ++it;
            minRepeat = 0; maxRepeat = 1;
        }
        else {
            minRepeat = 1; maxRepeat = 1;
        }


        newOp->setMinRepeat(minRepeat);
        newOp->setMaxRepeat(maxRepeat);
        regexOps.push_back(newOp);
        ++it;
    }

    return regexOps;
}

void clearRegex(vector<RegexOperator*> regex) {
    regex.clear();
}
