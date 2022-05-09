#include <cassert>
#include <string>
#include <vector>

using namespace std;


/* This class represents a range in a string, as a pair of indexes.  The "start"
 * index is inclusive, and the "end" index is exclusive, so that the range
 * [1, 5) represents the substring that starts at index 1 and ends at index 4;
 * index 5 is one past the last character in the substring.
 *
 * The "start" and "end" indexes are public access, so that they can be
 * accessed and manipulated directly.
 *
 * A range with identical "start" and "end" values indicates an empty string.
 *
 * The start and end indexes are also allowed to be -1, to indicate an invalid
 * range.
 */
class Range {
public:
    // The starting index of the range (inclusive)
    int start;
    
    // The ending index of the range (exclusive)
    int end;

    // Initialize a Range object with the specified start and end indexes
    Range(int start_, int end_) {
        assert(start_ <= end_);
        assert(start_ >= -1);
        assert(end_ >= -1);

        start = start_;
        end = end_;
    }
    
    // Initialize a Range object to the range [0, 0).
    Range() {
        start = 0;
        end = 0;
    }
};


/* A class for representing operations that can be performed in a regular
 * expression.
 */
class RegexOperator {
    // The minimum and maximum number of times the operator is *required* to
    // match.  The minimum value must be at least 0.  The maximum value must be
    // at least -1; -1 indicates "unlimited matches", and all other values
    // specify an actual maximum number of matches.
    int minRepeat, maxRepeat;
    
    // A vector of ranges where the regex operator has matched the test string.
    vector<Range> matches;
    
public:
    RegexOperator();

    // Operations to support optional and repeat operations.
    int getMinRepeat() const;
    int getMaxRepeat() const;
    void setMinRepeat(int n);
    void setMaxRepeat(int n);

    // Operations to support backtracking
    void clearMatches();
    void pushMatch(const Range &r);
    int numMatches() const;
    Range popMatch();

    virtual ~RegexOperator() {}

    // Match Operation
    virtual bool match(string const& s, Range& r) const = 0;
};

/*
 * Match a specific character in the string.
 */
class MatchChar: public RegexOperator {
    char matchedChar;

public:
    MatchChar(char c_);
    ~MatchChar(){};

    // Match Operation
    bool match(string const& s, Range& r) const override;
};

/*
 * Match any character in the string.
 */
class MatchAny: public RegexOperator {
public:
    MatchAny() = default;
    ~MatchAny(){};
    bool match(string const& s, Range& r) const override;
};

/*
 * Match any character from a set of specified characters.
 */
class MatchFromSubset: public RegexOperator {
    string subset;

public:
    MatchFromSubset(string const& subset_);
    ~MatchFromSubset(){};

    bool match(string const& s, Range& r) const override;
};

/*
 * Match characters not in subset
 */
class ExcludeFromSubset: public RegexOperator {
    string subset;

public:
    ExcludeFromSubset(string const& subset_);
    ~ExcludeFromSubset(){};

    bool match(string const& s, Range& r) const override;

};

vector<RegexOperator *> parseRegex(const string &expr);
void clearRegex(vector<RegexOperator *> regex);
