/**
 *
 * AUTHORS: <Roie Malykin>
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test other symbols'.',',':' ") 
{
    string text = "murloc, love . his :wife";
    CHECK(find(text, "murloc") != string("murloc"));//False
    CHECK(find(text, "murloc,") != string("murloc"));//False
    CHECK(find(text, "love") != string("love"));//False
    CHECK(find(text, "his :") != string("his"));//False
    CHECK(find(text, "wife") != string("wife"));//False
    CHECK(find(text, ":wife") != string(":wife"));//False
    
}
TEST_CASE("Test  backwords") 
{
    string text = "Yossi baKinor issOy";
    CHECK(find(text, "Yossi") == string("Yossi"));
    CHECK(find(text, "yoSSi") == string("issoy"));
    CHECK(find(text, "baKinor") != string("ronikab"));//False
    CHECK(find(text, "baKinor") != string("roniKab"));//False   
}

TEST_CASE("Test replacement of p and b") 
{
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    
}

TEST_CASE("Test replacement of lower-case and upper-case")
 {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here */
}
TEST_CASE("Test replacement of v and w") 
{
    string text = "View throught a window";
    CHECK(find(text, "Wiev") == string("View"));
    CHECK(find(text, "view") == string("View"));
 CHECK(find(text, "wiev") == string("View"));
    CHECK(find(text, "View") == string("View"));
    CHECK(find(text, "Vindow") == string("window"));
    CHECK(find(text, "Window") == string("window"));
CHECK(find(text, "vindow") == string("window"));
    CHECK(find(text, "vindow") == string("window"));
   CHECK(find(text, "Vindov") == string("window"));
    CHECK(find(text, "Window") == string("window"));
CHECK(find(text, "Vindov") == string("window"));
    CHECK(find(text, "WindoV") == string("window")); 
}

TEST_CASE("Test replacement of p and f") 
{
    string text = "five pour Feet fure is preferable pffft";
    CHECK(find(text, "Five") == string("five"));
 CHECK(find(text, "five") == string("five"));
 CHECK(find(text, "pive") == string("five"));
 CHECK(find(text, "Pive") == string("five"));
    CHECK(find(text, "pure") == string("fure"));
    CHECK(find(text, "Pure") == string("fure"));
    CHECK(find(text, "four") == string("pour"));
CHECK(find(text, "Four") == string("pour"));
CHECK(find(text, "pffft") == string("pffft"));
CHECK(find(text, "pfft") != string("pffft")); // False
CHECK(find(text, "ppfft") == string("pffft"));
CHECK(find(text, "pfppt") == string("pffft"));
CHECK(find(text, "fffft") == string("pffft"));
CHECK(find(text, "pfffo") != string("pffft")); // False
    CHECK(find(text, "pffft") == string("pffft"));
CHECK(find(text, "Freferable") == string("preferable"));
CHECK(find(text, "prePerable") == string("preferable"));

}

TEST_CASE("Test replacement of f and b with recurring words") 
{
    string text = "fig boose Big balls ";
    CHECK(find(text, "fig") == string("fig"));
    CHECK(find(text, "big") == string("fig"));
    CHECK(find(text, "Big") == string("fig"));
    CHECK(find(text, "Big") == string("Big"));// False , second word;
    CHECK(find(text, "pffft") == string("pffft")); // False dont exist 
}
TEST_CASE("Test replacement of b and f") 
{
    string text = "feak frick bake foring nico let go fowling";
    CHECK(find(text, "beak") == string("feak"));
	CHECK(find(text, "Beak") == string("feak"));
    CHECK(find(text, "Brick") == string("frick"));
	CHECK(find(text, "brick") == string("frick"));
    CHECK(find(text, "fake") == string("bake"));
	CHECK(find(text, "Fake") == string("bake"));
	CHECK(find(text, "Boring") == string("foring"));
	CHECK(find(text, "boring") == string("foring"));
    CHECK(find(text, "bate") == string("fate"));
	CHECK(find(text, "Bate") == string("fate"));
	CHECK(find(text, "bowling") == string("fowling"));
    
}
TEST_CASE("Test replacement of g and j") 
{
    string text = "juest get gews  gogging giggle";
    CHECK(find(text, "jews") == string("gews"));
    CHECK(find(text, "Jews") == string("gews"));
    CHECK(find(text, "jet") == string("get"));
    CHECK(find(text, "Jet") == string("get"));	
    CHECK(find(text, "guest") == string("juest"));
    CHECK(find(text, "Guest") == string("juest"));
    CHECK(find(text, "jueSt") == string("juest"));
	CHECK(find(text, "jogging") == string("gogging"));
	CHECK(find(text, "Jogging") == string("gogging"));
	CHECK(find(text, "gojjing") == string("gogging"));
	CHECK(find(text, "JogJing") == string("gogging"));
	CHECK(find(text, "joJjing") == string("gogging"));
	CHECK(find(text, "jojjing") == string("gogging"));
	CHECK(find(text, "jijjle") == string("giggle"));
    CHECK(find(text, "jijjle") == string("giggle"));
}
TEST_CASE("Test replacement of c and k") 
{
    string text = "I love my Chiccen and koca kola in the morning";
    CHECK(find(text, "chicken") == string("Chiccen"));
	CHECK(find(text, "ChicKen") == string("Chiccen"));
    CHECK(find(text, "coca") == string("koka"));
	CHECK(find(text, "coCa") == string("koka"));
	CHECK(find(text, "Coca") == string("koka"));
    CHECK(find(text, "cola") == string("kola"));
	CHECK(find(text, "Cola") == string("kola"));
}
TEST_CASE("Test replacement of k and c") 
{
    string text = "krakk kokaine";
    CHECK(find(text, "crack") == string("krakk"));
	CHECK(find(text, "crakk") == string("krakk"));
	CHECK(find(text, "cracC") == string("krakk"));
	CHECK(find(text, "Crack") == string("krakk"));
	CHECK(find(text, "crack") == string("krakk"));
	CHECK(find(text, "Krack") == string("krakk"));
    CHECK(find(text, "cocain") == string("kokaine"));
    CHECK(find(text, "cokain") == string("kokaine"));
    CHECK(find(text, "cocaine") == string("kokaine"));
    CHECK(find(text, "cokaine") == string("kokaine"));
    CHECK(find(text, "Cocaine") == string("kokaine"));
    CHECK(find(text, "Kocaine") == string("kokaine"));
    CHECK(find(text, "Cokaine") == string("kokaine"));

}
TEST_CASE("Test replacement of k and q") 
{
    string text = "question queez squeez queue ";
    CHECK(find(text, "kuestion") == string("question"));
    CHECK(find(text, "Kuestion") == string("question"));
    CHECK(find(text, "kueez") == string("queez"));
    CHECK(find(text, "Kueez") == string("queez"));
    CHECK(find(text, "skueez") == string("squeez"));
    CHECK(find(text, "sKueez") == string("squeez"));
    CHECK(find(text, "kueez") == string("queez"));
    CHECK(find(text, "Kueez") == string("queez"));
    CHECK(find(text, "kueue") == string("queue"));
    CHECK(find(text, "Kueue") == string("queue"));
}
TEST_CASE("Test replacement of q and k") 
{
    string text = "keep the koala and kangaroo kill kiss kick";
    CHECK(find(text, "qeep") == string("keep"));
    CHECK(find(text, "Qeep") == string("keep"));
    CHECK(find(text, "Qoala") == string("koala"));
    CHECK(find(text, "qoala") == string("koala"));
	CHECK(find(text, "qqoala") != string("koala"));
	CHECK(find(text, "qangaroo") == string("kangaroo"));
	CHECK(find(text, "Qangaroo") == string("kangaroo"));
    CHECK(find(text, "Qill") == string("kill"));
	CHECK(find(text, "qill") == string("kill"));
    CHECK(find(text, "qiss") == string("kiss"));
    CHECK(find(text, "Qiss") == string("kiss"));
    CHECK(find(text, "qicq") == string("kick"));
    CHECK(find(text, "Qicq") == string("kick"));
    CHECK(find(text, "kick") == string("kick"));
}
TEST_CASE("Test replacement of q and c") 
{
    string text = "luqk roqk cuirk cuary qar duqk luQk";
    CHECK(find(text, "luck") == string("luqk"));
	CHECK(find(text, "Luck") == string("luqk"));
    CHECK(find(text, "Rock") == string("roqk"));
    CHECK(find(text, "rock") == string("roqk"));
    CHECK(find(text, "Quirk") == string("cuirk"));
	CHECK(find(text, "quirk") == string("cuirk"));
	CHECK(find(text, "Quary") == string("cuary"));
	CHECK(find(text, "Car") == string("qar"));
	CHECK(find(text, "car") == string("qar"));
	CHECK(find(text, "Duck") == string("duqk"));
	CHECK(find(text, "duck") == string("duqk"));
	CHECK(find(text, "luck") == string("luQk"));
	CHECK(find(text, "Luck") == string("luQk"));
	CHECK(find(text, "luCk") == string("luQk"));
}
TEST_CASE("Test replacement of s and z") 
{
    string text = "saZalamel AzziZtent sombie";
    CHECK(find(text, "zasalamel") == string("saZalamel"));
	CHECK(find(text, "Zasalamel") == string("saZalamel"));
	CHECK(find(text, "zasalamel") == string("saZalamel"));
	CHECK(find(text, "SaSalamel") == string("saZalamel"));
	CHECK(find(text, "sasalamel") == string("saZalamel"));
	CHECK(find(text, "assistent") == string("AzziZtent"));
	CHECK(find(text, "azziZtent") == string("AzziZtent"));
	CHECK(find(text, "aSSiStent") == string("AzziZtent"));
	CHECK(find(text, "ASSISTENT") == string("AzziZtent"));
	CHECK(find(text, "Zombie") == string("sombie"));
	CHECK(find(text, "zombie") == string("sombie"));
	
   
}

TEST_CASE("Test replacement of d and t") 
{
    string text = "drash tash assiDent tot";
    CHECK(find(text, "dot") == string("tot"));
	CHECK(find(text, "dod") == string("tot"));
	CHECK(find(text, "TOT") == string("tot"));
	CHECK(find(text, "DOD") == string("tot"));
    CHECK(find(text, "Dash") == string("tash"));
	CHECK(find(text, "dash") == string("tash"));
    CHECK(find(text, "ASISDENT") == string("assisDent"));
	CHECK(find(text, "asistent") == string("assisDent"));
	CHECK(find(text, "asisdend") == string("assisDent"));
	CHECK(find(text, "ASISDEND") == string("assisDent"));
	CHECK(find(text, "ASISTEND") == string("assisDent"));
	CHECK(find(text, "ASISTENT") == string("assisDent"));
    CHECK(find(text, "trash") == string("drash"));
	CHECK(find(text, "Trash") == string("drash"));
	CHECK(find(text, "Drash") == string("drash"));
    
}
TEST_CASE("Test replacement of o and u") 
{
    string text = "duur MOo  sUOp ";
    CHECK(find(text, "soup") == string("sUOp"));
	CHECK(find(text, "SOUP") == string("sUOp"));
	CHECK(find(text, "SOOP") == string("sUOp"));
	CHECK(find(text, "Suup") == string("sUOp"));
	CHECK(find(text, "sUop") == string("sUOp"));
    CHECK(find(text, "moo") == string("MOo"));
	CHECK(find(text, "muu") == string("MOo"));
	CHECK(find(text, "mou") == string("MOo"));
	CHECK(find(text, "MOU") == string("MOo"));
    CHECK(find(text, "door") == string("duur"));
	CHECK(find(text, "dUUR") == string("duur"));
	CHECK(find(text, "DoOr") == string("duur"));
	CHECK(find(text, "Door") == string("duur"));
	CHECK(find(text, "duur") == string("duur"));
    
    
}

TEST_CASE("Test replacement of i and y") 
{
    string text = "ydyom Iconyc yotenheyym lyckrich";
    CHECK(find(text, "idiom") == string("ydyom"));
	CHECK(find(text, "Idiom") == string("ydyom"));
	CHECK(find(text, "Ydiom") == string("ydyom"));
	CHECK(find(text, "idyom") == string("ydyom"));
	CHECK(find(text, "YdYom") == string("ydyom"));
    CHECK(find(text, "iconic") == string("Iconyc"));
	CHECK(find(text, "Iconic") == string("Iconyc"));
	CHECK(find(text, "ICONIC") == string("Iconyc"));
	CHECK(find(text, "Yconic") == string("Iconyc"));
	CHECK(find(text, "Iconyc") == string("Iconyc"));
    CHECK(find(text, "yotenheyym") == string("yotenheyym"));
	CHECK(find(text, "YOTENHEYYM") == string("yotenheyym"));
	CHECK(find(text, "ioTenhIIm") == string("yotenheyym"));
	CHECK(find(text, "YoTeNhiIm") == string("yotenheyym"));
	CHECK(find(text, "iotenhiim") == string("yotenheyym"));
	CHECK(find(text, "yOtEnHeiYm") == string("yotenheyym"));
	CHECK(find(text, "yotenhiim") == string("yotenheyym"));
    CHECK(find(text, "lickrich") == string("lyckrich"));  
}
