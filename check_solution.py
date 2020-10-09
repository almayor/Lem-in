#!/usr/bin/env python3

import collections
import re
import sys


class Room:

	def __init__(self, name):
		self.name = name
		self.links = list()

	def add_link(self, name):
		self.links.append(name)


class Farm:

	cmd_regex = re.compile(r"L([0-9]{1,3})-(.*)")

	def __init__(self, nants):
		if nants == 0:
			raise ValueError("Numbers of ants should be greater than zero")
		self.nants = nants
		self.nrooms = 0
		self.rooms = dict()
		self.start = None
		self.end = None

	def add_room(self, name):
		if name in self.rooms:
			raise ValueError(f"Room {name} already exists")
		self.nrooms += 1
		self.rooms[name] = Room(name)
	
	def set_start(self, name):
		if self.start is not None:
			raise ValueError(f"START has already been set to {name}")
		self._check_room(name)
		self.start = name
		self.ants = [name] * self.nants

	def set_end(self, name):
		if self.end is not None:
			raise ValueError(f"END has already been set to {name}")
		self._check_room(name)
		self.end = name

	def add_link(self, name1, name2):
		self._check_room(name1)
		self._check_room(name2)
		self.rooms[name1].add_link(name2)
		self.rooms[name2].add_link(name1)

	def process(self, cmd):
		self._check_cmd(cmd)
		(ant, to) = self.cmd_regex.search(cmd).groups()
		ant = int(ant) - 1
		self.ants[int(ant)] = to
		self._check_occupancy()	

	def finish(self):
		if not all(room == self.end for room in self.ants):
			raise ValueError(
				f"Some ants haven't reaches the end"
			)

	def _check_occupancy(self):
		counts = collections.Counter(self.ants)
		for (room, occup) in counts.items():
			if room == self.start or room == self.end:
				continue
			if occup > 1:
				raise ValueError(
					f"Room {room} is occupied by {occup} ants"
				)

	def _check_cmd(self, cmd):
		if self.start is None:
			raise ValueError(f"Start isn't set")
		if self.end is None:
			raise ValueError(f"End isn't set")

		matches = self.cmd_regex.search(cmd).groups()
		if len(matches) != 2:
			raise ValueError("Invalid command: " + cmd)

		(ant, to) = matches
		ant = int(ant) - 1
		self._check_room(to)

		if ant > self.nants:
			raise ValueError(
				f"Command for ant #{ant} but there are only {self.nants} ants"
			)
		if to not in self.rooms[self.ants[ant]].links:
			raise ValueError(
				f"Room {self.ants[ant]} not connected to room {to}"
			)

	def _check_room(self, name):
		if name not in self.rooms:
			raise ValueError(f"Room {name} doesn't exist") 


class Parser:

	nants_regex = re.compile(r"^([0-9]+)$")
	room_regex  = re.compile(r"^([^L][^\s]*)\s+(-?[0-9]+)\s+(-?[0-9]+)$")
	link_regex	= re.compile(r"^([^L][^\s]*)-([^L][^\s]*)$")

	def __init__(self, file):
		self.file = file
		self.farm = None
		self.line = None

	def make_farm(self):
		self.readline()
		if not self.parse_nants():
			raise ValueError("Invalid number of ants: " + self.line)

		self.readline()
		while self.parse_room():
			self.readline()
		while self.parse_link():
			self.readline()

		if self.line != "":
			raise ValueError("Garbled input: " + self.line)

	def run_farm(self):
		count = 0
		self.readline()
		while self.line:
			count += 1
			for token in self.line.split():
				self.farm.process(token)
			self.readline()
		self.farm.finish()
		return count

	def parse_nants(self):
		match = self.nants_regex.search(self.line)
		if not match:
			return False
		self.farm = Farm(int(match.group(1)))
		return True

	def parse_room(self):
		if self.line == "##start" or self.line == "##end":
			command = self.line
			while self.line[0] == '#': self.readline()
		elif self.line[0] == "#":
			return True
		else:
			command = None

		match = self.room_regex.search(self.line)
		if not match:
			return False

		(name, _, _) = match.groups()
		self.farm.add_room(name)

		if command == "##start":
			self.farm.set_start(name)
		if command == "##end":
			self.farm.set_end(name)

		return True

	def parse_link(self):
		match = self.link_regex.search(self.line)
		if not match:
			return False
		(name1, name2) = match.groups()
		self.farm.add_link(name1, name2)
		return True

	def readline(self):
		self.line = self.file.readline().strip()
		if "required" in self.line:
			self.required = self.line
			self.readline()


# def id2names(farm, ids):
# 	names = sorted(farm.rooms.keys())
# 	names_li = list()
# 	for id_ in ids:
# 		names_li.append(names[id_])
# 	return names_li

# def path_exists(farm, rooms):
# 	from_ = rooms[0]
# 	for to in rooms[1:]:
# 		if to not in farm.rooms[from_].links:
# 			return False
# 		from_ = to
# 	return True

if __name__ == "__main__":
	parser = Parser(sys.stdin)
	try:
		parser.make_farm()
		count = parser.run_farm()
		print(f"Correct ({count} steps)")
		if hasattr(parser, "required"):
			print(parser.required)
	except:
		print("Last line read: " + parser.line)
		raise
