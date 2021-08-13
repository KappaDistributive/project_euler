from typing import Dict, Optional, Set
import networkx as nx


def add_node(number: int, graph: nx.DiGraph, leaves: Set[int]) -> bool:
  if not graph.has_node(number):
    graph.add_node(number)
    leaves.add(number)
    return True

  return False


def add_edge(source: int, destination: int, graph: nx.DiGraph, leaves: Set[int]) -> None:
  if source == 1:  # don't close cycle
    return False
  made_progress = False
  made_progress |= add_node(source, graph, leaves)
  made_progress |= add_node(destination, graph, leaves)
  if not graph.has_edge(source, destination):
    graph.add_edge(source, destination)
    leaves.discard(destination)
    made_progress = True

  return made_progress


def step(number: int) -> int:
  if number % 2 == 0:
    return number // 2
  return 3 * number + 1


def distance(source: int, graph: nx.DiGraph, distances: Dict[int, int]) -> None:
  if source not in distances.keys():
    distances[source] = distance(next(graph.neighbors(source)), graph, distances) + 1

  return distances[source]


if __name__ == "__main__":
  graph = nx.DiGraph()
  leaves = set()
  upper_bound = 1_000_000
  print("Creating graph...")
  for source in range(1, upper_bound):
    made_progress = True
    while made_progress:
      made_progress = False
      made_progress |= add_node(source, graph, leaves)
      destination = step(source)
      made_progress |= add_edge(source, destination, graph, leaves)
      source = destination

  print("Computing longest path...")
  distances: Dict[int, int] = {1: 0}
  for source in range(1, upper_bound):
    distance(source, graph, distances)

  answer = 1
  max_distance = 0
  for node, distance in distances.items():
    if distance > max_distance and node < upper_bound:
      answer = node
      max_distance = distance

  print(f"Collatz path {answer} --> {1} has length {max_distance}")

  # nx.nx_pydot.write_dot(graph, "graph.dot")
