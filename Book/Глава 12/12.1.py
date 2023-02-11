import sys

import pygame


def run_game():
    pygame.init()
    screen = pygame.display.set_mode((800, 800))
    pygame.display.set_caption("Nebo")

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()

        screen.fill((40, 40, 230))
        pygame.display.flip()


run_game()