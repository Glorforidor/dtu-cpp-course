#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
SongDatabase::SongDatabase()
{
    this->songs.push_back("Penny Lane");
    this->songsInfo["Penny Lane"] = {"https://youtu.be/S-rB0pHI9fU", 8};

    this->songs.push_back("Trololo");
    this->songsInfo["Trololo"] = {"https://youtu.be/oavMtUWDBTM", 10};

    this->songs.push_back("Ob-La-Di, Ob-La-Da");
    this->songsInfo["Ob-La-Di, Ob-La-Da"] = {"https://youtu.be/_J9NpHKrKMw", 2};

    this->songs.push_back("Don't Worry, Be Happy");
    this->songsInfo["Don't Worry, Be Happy"] = {"https://youtu.be/d-diB65scQU", 3};

    this->songs.push_back("Leave My Kitten Alone");
    this->songsInfo["Leave My Kitten Alone"] = {"https://youtu.be/7BKsy9-Bvok", 5};
}

// Task 3(a).  Implement this method
void SongDatabase::display()
{
    for (auto song : songs)
    {
        Info info = songsInfo[song];
        cout << "title=" << song << "; "
             << "url=" << info.url << "; "
             << "score=" << info.score << endl;
    }
}

// Task 3(b).  Implement this method
bool SongDatabase::addSong(string title, string url, unsigned int score)
{
    // A key does not exist in the map if find points to end.
    if (songsInfo.find(title) != songsInfo.end())
    {
        return false;
    }

    // This can not go to 11 :(
    if (score > 10)
    {
        return false;
    }

    songs.push_back(title);
    songsInfo[title] = {url, score};

    return true;
}

// Task 3(a).  Implement this method
void SongDatabase::searchSongs(string howGood)
{
    for (auto song : songs)
    {
        Info info = songsInfo[song];
        // Use these for score ranges.
        unsigned int start = 0;
        unsigned int end = 0;
        if (howGood == "abysmal")
        {
            start = 0;
            end = 3;
        }
        else if (howGood == "lousy")
        {
            start = 3;
            end = 5;
        }
        else if (howGood == "meh")
        {
            start = 5;
            end = 7;
        }
        else if (howGood == "cool")
        {
            start = 7;
            end = 9;
        }
        else if (howGood == "OMG")
        {
            start = 9;
        }

        // Nothing will be printed if start = 0 and end = 0 since
        // the equality check will be invalid (start <= 0 and end < 0) == FALSE.
        // Ignore the end if howGood == "OMG"! as it only need to check
        // start is greater than or equal to 9.
        if (start <= info.score && (info.score < end || howGood == "OMG"))
        {
            cout << "title=" << song << "; "
                 << "url=" << info.url << "; "
                 << "score=" << info.score << endl;
        }
    }
}
