// Name:        Timmy Truong
// ID:          ID#20772704
// Date:        September 26, 2018
// Course:      SYDE 121
// Lab room:    WEEF Lab - E2 1792
// Assignment:  Lab Assignment #2
// Exercise:    Exercise #3
// File Name:   lab03_03.cpp

//              I hereby declare that this code, submitted for credit for the course
//              SYDE121, is a product of my own efforts.  This coded solution has
//              not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project:     Astrology Signs

/*

 * OUTLINE
 * 1.declare variables and constants
 * 2.find outputs via https://www.astrology-zodiac-signs.com/ & enter as strings
 * 3.ask for birthday input
 * 4.check for invalid birthdays
 * 5.if valid, check for zodiac sign
 * 6.output corresponding string

 * TEST VALUES AND RANGE
 * The user must enter a valid birthday
 * ie. month has to be between 1 and 12
 * ie day must be between 1 - 29/30/31 depending on the month

 */

#include <iostream>

using namespace std;

int main() {
    // declare variables
    int month, day;

    // string outputs
    string aquarius = "Aquarius-born are shy and quiet , but on the other hand they can be eccentric and energetic. However, in both cases, they are deep thinkers and highly intellectual people who love helping others. They are able to see without prejudice, on both sides, which makes them people who can easily solve problems. Aquarius is an air sign, and as such, uses his mind at every opportunity. If there is no mental stimulation, they are bored and lack a motivation to achieve the best result. They are compatible with Leo and Sagittarius. \nThis excerpt is adapted from: \"https://www.astrology-zodiac-signs.com/zodiac-signs/aquarius/\".";
    string pisces = "Pisces are very friendly, so they often find themselves in a company of very different people. Pisces are selfless, they are always willing to help others, without hoping to get anything back. Pisces is a Water sign and as such this zodiac sign is characterized by empathy and expressed emotional capacity. They are compatible to Virgo and Taurus. \nThis excerpt is adapted from: \"http://www.astrology-zodiac-signs.com/zodiac-signs/pisces/\".";
    string aries = "Aries rules the head and leads with the head, often literally walking head first, leaning forwards for speed and focus. Its representatives are naturally brave and rarely afraid of trial and risk. They possess youthful strength and energy, regardless of their age and quickly perform any given tasks. Thanks to its ruling planet Mars and the fact it belongs to the element of Fire, Aries is one of the most active zodiac signs. It is in their nature to take action, sometimes before they think about it well. They are compatible with Libra and Leo. \nThis excerpt is adapted from \"https://www.astrology-zodiac-signs.com/zodiac-signs/aries/\".";
    string taurus = "Taurus is the sign that harvests the fruits of labor. They feel the need to always be surrounded by love and beauty, turned to the material world, hedonism, and physical pleasures. People born with their Sun in Taurus are sensual and tactile, considering touch and taste the most important of all senses. Taurus is an Earth sign, and has the ability to see things from a grounded, practical and realistic perspective. They are compatible with Scorpio and Cancer. \n This excerpt is adapted from:  \"https://www.astrology-zodiac-signs.com/zodiac-signs/taurus/\".";
    string gemini = "Gemini represents two different personalities in one and you will never be sure which one you will face. They are sociable, communicative and ready for fun, with a tendency to suddenly get serious, thoughtful and restless. They are fascinated with the world itself, extremely curious, with a constant feeling that there is not enough time to experience everything they want to see. The sign of Gemini belongs to the element of Air, and this connects it to all aspects of the mind. They are compatible with Sagittarius and Aquarius. \nThis excerpt is adapted from \"https://www.astrology-zodiac-signs.com/zodiac-signs/gemini/\".";
    string cancer = "Deeply intuitive and sentimental, Cancer can be one of the most challenging zodiac signs to get to know. They are very emotional and sensitive, and care deeply about matters of the family and their home. Cancer is sympathetic and attached to people they keep close. Those born with their Sun in Cancer are very loyal and able to empathize with other people's pain and suffering. The sign of Cancer belongs to the element of Water. Guided by emotion and their heart, they could have a hard time blending into the world around them. They are compatible with Capricorn and Taurus. \nThis excerpt is adapted from: \"https://www.astrology-zodiac-signs.com/zodiac-signs/cancer/\".";
    string leo = "People born under the sign of Leo are natural born leaders. They are dramatic, creative, self-confident, dominant and extremely difficult to resist, able to achieve anything they want to in any area of life they commit to. There is a specific strength to a Leo and their \"king of the jungle\" status. Leo often has many friends for they are generous and loyal. Leo belongs to the element of Fire. This makes them warmhearted, in love with life, trying to laugh and have a good time. They are compatible with Aquarius and Gemini. \nThis excerpt is adapted from: \"https://www.astrology-zodiac-signs.com/zodiac-signs/leo/\".";
    string virgo = "Virgos are always paying attention to the smallest details and their deep sense of humanity makes them one of the most careful signs of the zodiac. Their methodical approach to life ensures that nothing is left to chance, and although they are often tender, their heart might be closed for the outer world. This is a sign often misunderstood, not because they lack the ability to express, but because they won’t accept their feelings as valid, true, or even relevant when opposed to reason. Virgo is an Earth sign. This will lead to a strong character, but one that prefers conservative, well-organized things and a lot of practicality in their everyday life. They are compatible with Pisces and Cancer. \nThis excerpt is adapted from: \"https://www.astrology-zodiac-signs.com/zodiac-signs/virgo/\".";
    string libra = "People born under the sign of Libra are peaceful, fair, and they hate being alone. Partnership is very important for them, as their mirror and someone giving them the ability to be the mirror themselves. These individuals are fascinated by balance and symmetry, they are in a constant chase for justice and equality, realizing through life that the only thing that should be truly important to themselves in their own inner core of personality. The sign of Libra is an Air sign, giving these individuals constant mental stimuli, strong intellect and a keen mind. They will be inspired by good books, insurmountable discussions and people who have a lot to say. They are compatible with Aries and Sagittarius. \nThis excerpt is adapted from: \"https://www.astrology-zodiac-signs.com/zodiac-signs/libra/\".";
    string scorpio = "Scorpio-born are passionate and assertive people. They are determined and decisive, and will research until they find out the truth. Scorpio is a great leader, always aware of the situation and also features prominently in resourcefulness. Scorpio is a Water sign and lives to experience and express emotions. Although emotions are very important for Scorpio, they manifest them differently than other water signs. They are compatible with Taurus and Cancer. \nThis excerpt is adapted from: \"https://www.astrology-zodiac-signs.com/zodiac-signs/scorpio/\".";
    string sagittarius = "Sagittarius is one of the biggest travelers among all zodiac signs. Their open mind and philosophical view motivates them to wander around the world in search of the meaning of life. Sagittarius is extrovert, optimistic and enthusiastic, and likes changes. Sagittarius-born are able to transform their thoughts into concrete actions and they will do anything to achieve their goals. Sagittarius is a fire sign and needs to be constantly in touch with the world to experience as much as possible. They are compatible with Gemini and Aries. \nThis excerpt is adapted from: \"https://www.astrology-zodiac-signs.com/zodiac-signs/sagittarius/\".";
    string capricorn = "Capricorn is a sign that represents time and responsibility, and its representatives are traditional and often very serious by nature. These individuals possess an inner state of independence that enables significant progress both in their personal and professional lives. They are masters of self-control and have the ability to lead the way, make solid and realistic plans, and manage many people who work for them at any time. Belonging to the element of Earth, this is the last sign in the trio of practicality and grounding. Not only do they focus on the material world, but they have the ability to use the most out of it. They are compatible with Taurus and Cancer. \nThis excerpt is adapted from: \"https://www.astrology-zodiac-signs.com/zodiac-signs/capricorn/\".";

    // input
    cout << "What is your birth month? (Please enter as digits, i.e. January - 1, February - 2, ...) ";
    cin >> month;
    cout << "What is your birth day? ";
    cin >> day;

    // INVALID CONDITIONS
    if (month <= 0 || month > 12) {
        cout << "Invalid month. The program will now quit." << endl;
        return 1;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day < 1 || day > 31) {
            cout << "Invalid day. The program will now quit." << endl;
            return 1;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day < 1 || day > 30) {
            cout << "Invalid day. The program will now quit." << endl;
            return 1;
        }
    }
    if (month == 2) {
        if (day < 1 || day > 29) {
            cout << "Invalid month. The program will now quit." << endl;
            return 1;
        }
    }

    // determine the astrological sign
    if ((month == 1 && day <= 20) || (month == 2 && day <= 18)) {
        cout << aquarius << endl;
    }
    if ((month == 2 && day >= 19) || (month == 3 && day <= 20)) {
        cout << pisces << endl;
    }
    if ((month == 3 && day >= 21) || (month == 4 && day <= 19)) {
        cout << aries << endl;
    }
    if ((month == 4 && day >= 20) || (month == 5 && day <= 20)) {
        cout << taurus << endl;
    }
    if ((month == 5 && day >= 21) || (month == 6 && day <= 20)) {
        cout << gemini << endl;
    }
    if ((month == 6 && day >= 21) || (month == 7 && day <= 22)) {
        cout << cancer << endl;
    }
    if ((month == 7 && day >= 23) || (month == 8 && day <= 22)) {
        cout << leo << endl;
    }
    if ((month == 8 && day >= 23) || (month == 9 && day <= 22)) {
        cout << virgo << endl;
    }
    if ((month == 9 && day >= 23) || (month == 10 && day <= 22)) {
        cout << libra << endl;
    }
    if ((month == 10 && day >= 23) || (month == 11 && day <= 21)) {
        cout << scorpio << endl;
    }
    if ((month == 11 && day >= 22) || (month == 12 && day <= 21)) {
        cout << sagittarius << endl;
    }
    if ((month == 12 && day >= 22) || (month == 1 && day <= 19)) {
        cout << capricorn << endl;
    }
    return 0;
}