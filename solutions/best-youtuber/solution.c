// A program that constructs a list of YouTube videos from input.
// It then prints the YouTuber from among those videos with the greatest
// likes-to-video ratio.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 128

struct video {
    char creator[BUFFER_SIZE];
    int likes;
    struct video *next;
};

struct youtuber {
    char name[BUFFER_SIZE];
    int num_videos;
    int total_likes;
    struct youtuber *next;
};

void find_best_youtuber(struct youtuber *head_youtuber);
struct youtuber *populate_youtuber_list(struct video *head_video);
struct youtuber *create_youtuber(char *name);
bool already_in_list(char *video_creator, struct youtuber *head_youtuber);
void update_youtubers_with_info(struct youtuber *head_youtuber, struct video *head_video);
void print_all_youtubers(struct youtuber *head);

// provided functions
struct video *populate_video_list_from_input(void);
struct video *create_video(char *creator, int likes);
void print_all_videos(struct video *head);

int main(void) {
    struct video *head_video = populate_video_list_from_input();
    // print_all_videos(head_video);
    
    struct youtuber *head_youtuber = populate_youtuber_list(head_video);
    update_youtubers_with_info(head_youtuber, head_video);
    // print_all_youtubers(head_youtuber);
    find_best_youtuber(head_youtuber);
    
    return 0;
}

void find_best_youtuber(struct youtuber *head_youtuber) {
    double max_ratio = -1;
    struct youtuber *best_youtuber = NULL;
    bool tie = false;
    
    struct youtuber *current_youtuber = head_youtuber;
    while (current_youtuber != NULL) {
        double num_videos = current_youtuber->num_videos;
        double total_likes = current_youtuber->total_likes;
        double ratio = total_likes / num_videos;
        if (max_ratio == ratio) {
            tie = true;
        } else if (max_ratio < ratio) {
            tie = false;
            max_ratio = ratio;
            best_youtuber = current_youtuber;
        }
        current_youtuber = current_youtuber->next;
    }
    
    if (tie) {
        printf("It's a tie! There is no best YouTuber.\n");
        return;
    }
    
    printf(
        "%s is the best YouTuber.\n"
        "Number of videos: %d\n"
        "Total likes: %d\n",
        best_youtuber->name,
        best_youtuber->num_videos,
        best_youtuber->total_likes
    );
}

struct youtuber *populate_youtuber_list(struct video *head_video) {
    struct video *current_video = head_video;
    struct youtuber *head_youtuber = NULL;
    struct youtuber *current_youtuber = NULL;
    while (current_video != NULL) {
        if (head_youtuber == NULL) {
            head_youtuber = create_youtuber(current_video->creator);
            current_youtuber = head_youtuber;
        } else if (!already_in_list(current_video->creator, head_youtuber)) {
            current_youtuber->next = create_youtuber(current_video->creator);
            current_youtuber = current_youtuber->next;
        }
        current_video = current_video->next;
    }
    return head_youtuber;
}

struct youtuber *create_youtuber(char *name) {
    struct youtuber *new_youtuber = malloc(sizeof(struct youtuber));
    strcpy(new_youtuber->name, name);
    new_youtuber->num_videos = 0;
    new_youtuber->total_likes = 0;
    new_youtuber->next = NULL;
    return new_youtuber;
}

bool already_in_list(char *video_creator, struct youtuber *head_youtuber) {
    struct youtuber *current_youtuber = head_youtuber;
    while (current_youtuber != NULL) {
        if (strcmp(video_creator, current_youtuber->name) == 0) {
            return true;
        }
        current_youtuber = current_youtuber->next;
    }
    return false;
}

void update_youtubers_with_info(struct youtuber *head_youtuber, struct video *head_video) {
    struct youtuber *current_youtuber = head_youtuber;
    while (current_youtuber != NULL) {
        struct video *current_video = head_video;
        while (current_video != NULL) {
            if (strcmp(current_youtuber->name, current_video->creator) == 0) {
                current_youtuber->num_videos += 1;
                current_youtuber->total_likes += current_video->likes;
            }
            current_video = current_video->next;
        }
        current_youtuber = current_youtuber->next;
    }
}

void print_all_youtubers(struct youtuber *head) {
    int i = 0;
    struct youtuber *current = head;
    while (current != NULL) {
        printf(
            "youtuber_%d = {\n"
            "    name: \"%s\",\n"
            "    num_videos: %d\n"
            "    total_likes: %d\n"
            "}",
            i,
            current->name,
            current->num_videos,
            current->total_likes
        );
        if (current->next != NULL) {
            printf(",");
        }
        printf("\n");
        i++;
        current = current->next;
    }
}

// provided functions

struct video *populate_video_list_from_input(void) {
    struct video *head_video = NULL;
    struct video *current_video = NULL;
    
    char input_line[BUFFER_SIZE];
    while (fgets(input_line, BUFFER_SIZE, stdin) != NULL) {
        char creator[BUFFER_SIZE];
        int likes;
        sscanf(input_line, "%[^,],%d", creator, &likes);
        
        if (head_video == NULL) {
            head_video = create_video(creator, likes);
            current_video = head_video;
        } else {
            current_video->next = create_video(creator, likes);
            current_video = current_video->next;
        }
    }
    
    return head_video;
}

struct video *create_video(char *creator, int likes) {
    struct video *new_video = malloc(sizeof(struct video));
    strcpy(new_video->creator, creator);
    new_video->likes = likes;
    new_video->next = NULL;
    return new_video;
}

void print_all_videos(struct video *head) {
    int i = 0;
    struct video *current = head;
    while (current != NULL) {
        printf(
            "video_%d = {\n"
            "    creator: \"%s\",\n"
            "    likes: %d\n"
            "}",
            i,
            current->creator,
            current->likes
        );
        if (current->next != NULL) {
            printf(",");
        }
        printf("\n");
        i++;
        current = current->next;
    }
}
