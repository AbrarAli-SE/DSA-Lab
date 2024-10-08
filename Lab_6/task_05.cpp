#include <iostream>
#include <string>
using namespace std;

class Song
{
public:
    string title;
    string artist;
    Song *prev;
    Song *next;

    Song(string t, string a)
    {
        title = t;
        artist = a;
        prev = NULL;
        next = NULL;
    }
};

// Function to add a new song to the end of the playlist
void addSongToEnd(Song *&head, const string &title, const string &artist)
{
    Song *newSong = new Song(title, artist);
    if (head == NULL)
    {
        head = newSong;
        return;
    }
    Song *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newSong;
    newSong->prev = temp;
}

// Function to display the playlist forwards
void displayPlaylistForward(Song *head)
{
    if (head == NULL)
    {
        cout << "The playlist is empty.\n";
        return;
    }
    Song *temp = head;
    cout << "Playlist (Forward):\n";
    while (temp != NULL)
    {
        cout << temp->title << " by " << temp->artist << "\n";
        temp = temp->next;
    }
}

// Function to display the playlist backwards
void displayPlaylistBackward(Song *head)
{
    if (head == NULL)
    {
        cout << "The playlist is empty.\n";
        return;
    }
    Song *temp = head;
    // Move to the last song
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    cout << "Playlist (Backward):\n";
    while (temp != NULL)
    {
        cout << temp->title << " by " << temp->artist << "\n";
        temp = temp->prev;
    }
}

// Function to delete a song from the playlist
void deleteSong(Song *&head, const string &title)
{
    if (head == NULL)
    {
        cout << "The playlist is empty, cannot delete.\n";
        return;
    }

    Song *temp = head;

    // Find the song to delete
    while (temp != NULL)
    {
        if (temp->title == title)
        {
            // Found the song
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            else
            {
                head = temp->next; // Update head if it's the first song
            }
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            delete temp; // Free memory
            cout << "Deleted: " << title << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Song not found: " << title << "\n";
}

int main()
{
    Song *playlist = NULL;

    // Adding songs to the playlist
    addSongToEnd(playlist, "Song 1", "Artist 1");
    addSongToEnd(playlist, "Song 2", "Artist 2");
    addSongToEnd(playlist, "Song 3", "Artist 3");
    addSongToEnd(playlist, "Song 4", "Artist 4");
    addSongToEnd(playlist, "Song 5", "Artist 5");

    // Displaying the playlist
    displayPlaylistForward(playlist);
    displayPlaylistBackward(playlist);

    // Deleting a song
    deleteSong(playlist, "Song 3");

    // Displaying the playlist after deletion
    displayPlaylistForward(playlist);
    displayPlaylistBackward(playlist);

    // Attempt to delete a song that does not exist
    deleteSong(playlist, "Song 6");

    return 0;
}
