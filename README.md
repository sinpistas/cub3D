# cube3D
Cube3D

Notion temporal:
https://www.notion.so/2fbfac1d1ce780a7a18ecf35dcc3a574?v=2fbfac1d1ce781538164000c106e7a90&source=copy_link

Parser guide:

main
 │
 │ cub_scene_init
 │
 ▼
cub_parse_file(path)
 │
 ├─ cub_check_extension
 │
 ├─ open(fd)
 │
 ├─ cub_read_lines
 │   │
 │   ├─ get_next_line
 │   │
 │   └─ cub_process_line
 │       │
 │       ├─ cub_is_blank
 │       │
 │       ├─ cub_is_map_line ──┐
 │       │                   │
 │       ├─ cub_parse_id_line │ (NO / SO / WE / EA / F / C)
 │       │                   │
 │       └─ cub_map_push_line◄┘ (cuando empieza el mapa)
 │
 ├─ close(fd)
 │
 └─ cub_after_read
     │
     ├─ cub_finalize_map
     │   ├─ map_lines → char **map
     │   ├─ rectangularize with ' '
     │   └─ free map_lines
     │
     └─ cub_validate_scene
         │
         ├─ check textures (NO SO WE EA)
         ├─ check colors (F C)
         └─ cub_validate_map
             │
             ├─ cub_validate_cell
             │   ├─ cub_is_allowed
             │   └─ cub_cell_is_open
             │
             └─ cub_set_player (exactly one)
