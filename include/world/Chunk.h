#pragma once

#include <blocks/Block.h>

#include <misc/Xorshift.h>
#include <rendering/VBOCache.h>

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define CHUNK_SIZE (16)
#define CHUNK_HEIGHT (128)
#define CLUSTER_PER_CHUNK (CHUNK_HEIGHT / CHUNK_SIZE)

typedef struct {
	int y;
	Block blocks[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];

	uint32_t revision;

	uint16_t seeThrough;

	VBO_Block vbo;
	size_t vertices;
	uint32_t vboRevision;
	bool forceVBOUpdate;
} Cluster;

typedef enum { ChunkUsage_NotInUse, ChunkUsage_InUse, ChunkUsage_Undead, ChunkUsage_DeaderThanDead = ChunkUsage_Undead + 3 } ChunkMemoryUsage;

typedef enum {
	ChunkGen_Empty,  //
	ChunkGen_Terrain,
	ChunkGen_Finished  // Terrain | Decoration
} ChunkGenProgress;

typedef struct {
	// Die Gesamtanzahl! >= graphicalTasksRunning
	uint32_t tasksRunning;
	uint32_t graphicalTasksRunning;

	uint32_t uuid;

	ChunkMemoryUsage usage;
	ChunkGenProgress genProgress;

	int x, z;
	Cluster clusters[CLUSTER_PER_CHUNK];

	size_t revision;

	uint32_t displayRevision;
	bool forceVBOUpdate;
} Chunk;

extern Xorshift32 uuidGenerator;
extern const uint8_t _seethroughTable[6][6];
inline uint16_t ChunkSeeThrough(Direction in, Direction out) { return 1 << (uint16_t)(_seethroughTable[in][out]); }
inline bool ChunkCanBeSeenThrough(uint16_t visiblity, Direction in, Direction out) { return visiblity & (1 << (uint16_t)(_seethroughTable[in][out])); }

inline void Chunk_Init(Chunk* chunk, int x, int z) {
	memset(chunk, 0, sizeof(Chunk));

	chunk->x = x;
	chunk->z = z;
	for (int i = 0; i < CLUSTER_PER_CHUNK; i++) {
		chunk->clusters[i].y = i;
		chunk->clusters[i].seeThrough = UINT16_MAX;
	}
	chunk->usage = ChunkUsage_InUse;
	chunk->uuid = Xorshift32_Next(&uuidGenerator);
}

inline void Chunk_RequestGraphicsUpdate(Chunk* chunk, int cluster) {
	chunk->clusters[cluster].forceVBOUpdate = true;
	chunk->forceVBOUpdate = true;
}

inline Block Chunk_GetBlock(Chunk* chunk, int x, int y, int z) { return chunk->clusters[y / CHUNK_SIZE].blocks[x][y - (y / CHUNK_SIZE * CHUNK_SIZE)][z]; }
inline void Chunk_SetBlock(Chunk* chunk, int x, int y, int z, Block block) {
	Cluster* cluster = &chunk->clusters[y / CHUNK_SIZE];
	cluster->blocks[x][y - (y / CHUNK_SIZE * CHUNK_SIZE)][z] = block;
	++cluster->revision;
	++chunk->revision;
}